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
    bool solve(TreeNode* root, int k, unordered_set<int> &st){
        if(root == NULL) return false;

        if(st.count(k - root->val)){
            return true;
        }
        else
            st.insert(root->val);
            
        return solve(root->left, k, st) || solve(root->right, k, st);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> mp;
        return solve(root, k, mp);
    }
};