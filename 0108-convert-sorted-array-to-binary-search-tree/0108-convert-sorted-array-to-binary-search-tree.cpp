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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size());
    }
    TreeNode* buildTree(vector<int> &arr, int s, int l){
        if(l == s) return nullptr;

        int mid = s + (l-s)/2;

        TreeNode* node = new TreeNode(arr[mid]);
        node->left = buildTree(arr, s, mid);
        node->right = buildTree(arr, mid+1, l);

        return node;
    }
};