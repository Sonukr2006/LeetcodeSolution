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
    int solve(TreeNode* root, long long tar){
        if(root == NULL) return 0;
        return (root->val == tar ? 1 : 0) + solve(root->left, tar-root->val)+ solve(root->right, tar-root->val);
    }
    int pathSum(TreeNode* root, int Sum) {
        if(root == NULL) return 0;
        
        return solve(root, Sum) + pathSum(root->left, Sum) + pathSum(root->right, Sum);
    }
};