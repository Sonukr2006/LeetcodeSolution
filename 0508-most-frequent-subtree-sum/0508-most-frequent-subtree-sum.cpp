/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, unordered_map<int, int> &mp, int &count){
        if(!root) return 0;

        int left = dfs(root->left, mp, count);
        int right = dfs(root->right, mp, count);

        int sum = left+right+root->val;
        mp[sum]++;
        count = max(count, mp[sum]);
        return sum;

    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        int  maxCount = 0;
        dfs(root, mp, maxCount);
        vector<int> ans;
        for(auto it:mp){
            if(maxCount == it.second){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};