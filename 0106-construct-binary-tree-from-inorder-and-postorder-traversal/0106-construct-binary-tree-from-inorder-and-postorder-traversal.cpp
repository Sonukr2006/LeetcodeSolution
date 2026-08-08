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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
    TreeNode* build(vector<int> &postorder, int startPost, int endPost, vector<int> &inorder, int startIn, int endIn, map<int, int> &mp){
        if(startPost > endPost || startIn > endIn) return NULL;

        TreeNode* node = new TreeNode(postorder[endPost]);
        int inorderNodeIndex = mp[node->val];
        int numRight =  endIn-inorderNodeIndex;

        node->right = build(postorder, endPost-numRight, endPost-1, inorder, inorderNodeIndex+1, endIn, mp);
        int numLeft = inorderNodeIndex-startPost;
        node->left = build(postorder, startPost, endPost-numRight-1, inorder, startIn, inorderNodeIndex-1, mp);

        return node;
    }
    
};