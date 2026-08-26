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
    void solve(TreeNode* root, vector<int> &temp){
        if(!root) return;

        solve(root->left, temp);
        temp.push_back(root->val);
        solve(root->right, temp);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> temp;
        solve(root, temp);
        int diff = INT_MAX;
        for(int i = 1; i < temp.size(); ++i){
            diff = min(diff, temp[i]-temp[i-1]);
        }
        return diff;    
    }
};