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
    void solve(TreeNode* root, int &ans, int depth, int & maxDepth){
        if(root == NULL) return;

        if(depth > maxDepth){
            maxDepth = depth;
            ans = root->val;
        }
        solve(root->left, ans, depth+1, maxDepth);
        solve(root->right, ans, depth+1, maxDepth);

    }
    int findBottomLeftValue(TreeNode* root) {
        int  leftNode = 0;
        int maxDepth = -1;
        solve(root, leftNode, 0, maxDepth);
        return leftNode;
    }
};