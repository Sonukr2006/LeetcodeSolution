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
    
    bool checkTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            int left = 0;
            int right = 0;
            if(node->left){
                q.push(node->left);
                left = node->left->val;
            }
            if(node->right){
                q.push(node->right);
                right = node->right->val;
            }
            if(node->left != NULL && node->right != NULL){
                if(node->val != left+right) return false;
            }
        }

        return true;
    }
};