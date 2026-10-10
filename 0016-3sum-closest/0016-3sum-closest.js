/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    let n = nums.length;
    nums.sort((a, b) => a - b);
    let res = 0;
    let diff = Number.MAX_SAFE_INTEGER;
    for(let i = 0; i < n; i++){
       
        let j = i+1, k = n-1;
        while(j < k){
            let sum = nums[i]+ nums[j] + nums[k];
            let d = Math.abs(sum- target);
            if(d < diff){
                diff = d;
                res = sum;
            }

            if (sum < target) j++;
            else k--;
        }
    }
    return res;
};