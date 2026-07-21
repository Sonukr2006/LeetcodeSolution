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
    void solve(TreeNode* root,  map<int, map<int, multiset<int>>> &hashmap, int axis, int level){
        if(root == NULL) return;

        hashmap[axis][level].insert(root->val);

        solve(root->left, hashmap, axis-1, level+1);
        // hashmap[axis].push_back(root->val);
        solve(root->right, hashmap, axis+1, level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> hashmap;
        // hashmap[0][0].insert(root->val);
        solve(root, hashmap, 0, 0);

        vector<vector<int>> res;

        for(auto inner : hashmap){
            vector<int> row;
            for(auto innerMap : inner.second){
                for(auto mapVal : innerMap.second){
                    row.push_back(mapVal);
                }
            }
            res.push_back(row);
        }
        return res;
    }
};