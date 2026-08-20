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
    int currCount = 0;
    int maxCount = 0;
    vector<int> res;
    TreeNode* prev = NULL;
    void helper(TreeNode* root){
        if(root == NULL){
            return;
        }

        helper(root->left);

        if(prev && root->val == prev->val) currCount++;
        else currCount = 1;

        if(currCount > maxCount){
            maxCount = currCount;
            res.clear();

            res.push_back(root->val);
        }
        else if(maxCount == currCount){
            res.push_back(root->val);
        }
        prev = root;
        helper(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) return {};
        currCount = 0;
        maxCount = 0;
        res.clear();
        prev = NULL;

        helper(root);
        
        return res; 

    }
};