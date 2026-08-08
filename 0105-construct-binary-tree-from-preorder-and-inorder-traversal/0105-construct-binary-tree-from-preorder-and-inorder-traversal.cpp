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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
    TreeNode* build(vector<int> &preorder, int startPre, int endPre, vector<int> &inorder, int startIn, int endIn, map<int, int> &mp){
        if(startPre > endPre || startIn > endIn) return NULL;

        TreeNode* node = new TreeNode(preorder[startPre]);
        int inorderNodeIndex = mp[node->val];
        int numLeft =  inorderNodeIndex-startIn;

        node->left = build(preorder, startPre+1, startPre+numLeft, inorder, startIn, inorderNodeIndex-1, mp);
        node->right = build(preorder, startPre+numLeft+1, endPre, inorder, inorderNodeIndex+1, endIn, mp);

        return node;
    }
};