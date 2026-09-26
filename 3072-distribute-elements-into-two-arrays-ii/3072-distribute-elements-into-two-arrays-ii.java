class ST{
    int[] seg;
    int size;
    public ST(int n){
        this.size = n;
        seg = new int[4*n];
    }

    
    private void updateST(int ind, int low, int high, int i){
        if(low == high){
            seg[ind]++;
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = ind << 1| 1;
        int right = (ind + 1) << 1;

        if(i <= mid)
            updateST(left, low, mid, i);
        else
            updateST(right, mid+1, high, i);
        
        seg[ind] = seg[left] + seg[right];
    }

    private int queryST(int ind, int low, int high, int L, int R){
        // for no overlap condition
        if(high < L || low > R)
            return 0;
        
        // for complete overlap conditon
        if(low >= L && high <= R)
            return seg[ind];
        

        int mid = low + ((high - low )>> 1);
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        return queryST(left, low, mid, L, R) + queryST(right, mid+1, high, L, R);
    }

    public void update(int i){
        updateST(0, 0, size-1, i);
    }
    public int query(int L, int R){
        return queryST(0, 0, size-1, L, R);
    }
};
class Solution {
    public int[] resultArray(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int[] arr = nums.clone();

        Arrays.sort(arr);
        int cnt = 0;
        for(int num : arr){
            if (!mp.containsKey(num)) {
                mp.put(num, cnt++);
            }
        }
        int n = mp.size();
        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();

        ST st1 = new ST(n);
        ST st2 = new ST(n);

        arr1.add(nums[0]);
        arr2.add(nums[1]);
        st1.update(mp.get(nums[0]));
        st2.update(mp.get(nums[1]));

        for(int i = 2; i < nums.length; ++i){
            int ind = mp.get(nums[i]);
            int count1 = st1.query(ind+1, n-1);
            int count2 = st2.query(ind+1, n-1);

            if (count1 > count2) {
                arr1.add(nums[i]);
                st1.update(ind);
            } else if (count2 > count1) {
                arr2.add(nums[i]);
                st2.update(ind);
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.add(nums[i]);
                    st1.update(ind);
                } else {
                    arr2.add(nums[i]);
                    st2.update(ind);
                }
            }
        }
        int[] ans =  new int[nums.length];
        int index = 0;
        for(int ele  : arr1){
            ans[index++] = ele;
        }

        for(int ele  : arr2){
            ans[index++] = ele;
        }
        return ans;
    }
}