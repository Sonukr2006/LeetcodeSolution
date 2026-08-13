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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        q.push(root);

        // for root node
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        int depthNo = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* curr = q.front();
                q.pop();
                if(depthNo == depth-1){
                    TreeNode* node = new TreeNode(val);
                    TreeNode* node2 = new TreeNode(val);

                    node->left = curr->left;
                    node2->right = curr->right;
                    curr->left = node;
                    curr->right = node2;
                }

                if(curr->left)
                    q.push(curr->left);
                if(curr->right) 
                    q.push(curr->right);
            }
            depthNo+=1;
        }
        return root;

    }
};