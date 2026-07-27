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
    void solve(TreeNode* root, TreeNode* &node){
        if(root == NULL) return;

        solve(root->right, node);
        solve(root->left, node);

        root->right = node;
        root->left = NULL;

        node = root;
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;

        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* pre = curr->left;
                while(pre->right != NULL){
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;

        }
    }
};