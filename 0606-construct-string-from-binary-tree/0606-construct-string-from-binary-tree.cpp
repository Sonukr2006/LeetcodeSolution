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
    string solve(TreeNode* root){
        string str = "";
        if(root == NULL){
            return str;
        }

        str += to_string(root->val);

        string left = solve(root->left);
        string right = solve(root->right);
        if(!root->left && !root->right) return str;
        if(!root->left && root->right)
            return str + "()" + "(" + right + ")";
        if(!root->right && root->left)
            return str + "(" + left + ")";

        return str + "(" + left + ")" + "(" + right + ")";
    }
    string tree2str(TreeNode* root) {
        string res = "";


        return solve(root);
    }
};