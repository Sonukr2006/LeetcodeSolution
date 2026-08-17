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
class BSTIterator {
public:
    void pushAll(TreeNode* node){
        for(; node != NULL;){
            stack.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
    stack<TreeNode*> stack;
    bool reverse = true;
    BSTIterator(TreeNode* root, bool rev) {
        reverse = rev;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = stack.top();
        stack.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    
    bool hasNext() {;
        return !stack.empty();
        
    }
};

class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;


    }
};