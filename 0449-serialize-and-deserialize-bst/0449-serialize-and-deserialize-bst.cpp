/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        ostringstream out;
        out << root->val << " ";
        out << serialize(root->left);
        out << serialize(root->right);

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<int> vec;
        stringstream ss(data);
        string token;
        while(ss >> token){
            vec.push_back(stoi(token));
        }
        int index = 0;
        return build(vec, INT_MIN, INT_MAX, index);
    }
    TreeNode* build(const vector<int> &vac, int minVal, int maxVal, int &index){
        if(index >= vac.size())
            return nullptr;
        int val = vac[index];
        if(val < minVal || val > maxVal)
            return nullptr;
        index++;
        TreeNode* node = new TreeNode(val);

        node->left = build(vac, minVal, val-1, index);
        node->right = build(vac, val-1, maxVal, index); 
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;