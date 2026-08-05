/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void MarkParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &itsParent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i =0; i < size; ++i){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    itsParent[node->left] = node;
                    q.push(node->left);
                }

                if(node->right){
                    itsParent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    void findElement(unordered_map<TreeNode*, TreeNode*> itsParent, unordered_map<TreeNode*, bool> &st, vector<int> &ans, TreeNode* target, int k){
        queue<TreeNode*> q;
        q.push(target);
        st[target] = true;
        int dist = 0;

        while(!q.empty()){
            int size = q.size();

            if(dist++ == k){
                while(size--){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }

            for(int i = 0; i <  size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    if(!st[node->left]){
                        st[node->left] = true;
                        q.push(node->left);
                    }
                }
                if(node->right){
                    if(!st[node->right]){
                        st[node->right] = true;
                        q.push(node->right);
                    }
                }

                if(itsParent[node]){
                    if(!st[itsParent[node]]){
                        st[itsParent[node]] = true;
                        q.push(itsParent[node]);
                    }
                }


            }
            
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> itsParent;
        vector<int> ans;
        MarkParent(root, itsParent);
        unordered_map<TreeNode*, bool> st;
        findElement(itsParent, st, ans, target, k);

        return ans;
    }
};