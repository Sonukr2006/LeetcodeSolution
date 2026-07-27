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
    void getPath(vector<vector<int>> &ans, TreeNode* root, int tar, vector<int> &ds){
        if(root == NULL){
            return;
        }
        ds.push_back(root->val);

        if(root->left == NULL && root->right == NULL && tar == root->val){
            ans.push_back(ds);
            ds.pop_back();
            return ;
        }

        tar -= root->val;


        getPath(ans, root->left, tar, ds);
        getPath(ans, root->right, tar, ds);
        ds.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        getPath(ans, root, targetSum, ds);
        return ans;
    }
};