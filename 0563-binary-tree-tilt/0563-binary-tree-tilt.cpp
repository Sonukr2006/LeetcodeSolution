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
    int findTiltHealper(TreeNode* root, int &ans){
        if(root == NULL) return 0;

        int left = findTiltHealper(root->left, ans);
        int right = findTiltHealper(root->right, ans);

        ans += abs(left - right);

        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        int ans  = 0;
        findTiltHealper(root, ans);
        return ans;
    }
};