class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> stack;
        stringstream ss(preorder);
        string node;
        while(getline(ss, node, ',')){
            stack.push_back(node);

            while(stack.size() >= 3 && stack[stack.size() - 1] == "#" && stack[stack.size() - 2] == "#" &&  stack[stack.size() - 3] != "#") {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();

                stack.push_back("#");
            }
        }
        return stack.size() == 1 && stack[0] == "#";

    }
};