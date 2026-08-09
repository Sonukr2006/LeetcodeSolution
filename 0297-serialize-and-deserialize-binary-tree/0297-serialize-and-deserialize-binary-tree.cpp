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
    void serializeHelper(TreeNode* root, ostringstream &out){
        if(root == NULL)
            out << "null ";
        else{
            out << root->val << " ";
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    TreeNode* deserializeHelper(istringstream &in){
        string val;
        in >> val;
        if(val == "null") return NULL;

        TreeNode* root =  new TreeNode(stoi(val));
        root->left = deserializeHelper(in);
        root->right = deserializeHelper(in);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));