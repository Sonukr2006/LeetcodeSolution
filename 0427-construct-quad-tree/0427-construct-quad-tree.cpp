/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool valid(vector<vector<int>> arr, int i, int j, int Iend, int Jend){
        int val = arr[i][j];
        for(int k = i; k < Iend; ++k){
            for(int l = j; l < Jend; ++l){
                if(arr[k][l] != val) return false;
            }
        }
        return true;
    }
    Node* tree(vector<vector<int>> arr, int i, int j, int Iend, int Jend){
        int Imid = i + (Iend - i)/2;
        int Jmid =  j + (Jend - j)/2;
        Node* root = new Node(1, false);

        //topLeft 
        if(valid(arr, i, j, Imid, Jmid)){
            root->topLeft = new Node(arr[i][j], true);
        }else{
            root->topLeft  = tree(arr, i, j, Imid, Jmid);
        }

        //topRight
        if(valid(arr, i, Jmid, Imid, Jend)){
            root->topRight = new Node(arr[i][Jmid], true);
        }
        else{
            root->topRight = tree(arr, i, Jmid, Imid, Jend);
        }

        // bottomLeft
         if(valid(arr, Imid, j, Iend, Jmid)){
            root->bottomLeft = new Node(arr[Imid][j], true);

        }
        else{
            root->bottomLeft = tree(arr, Imid, j, Iend, Jmid);
        }

        //bottomRight
         if(valid(arr,Imid, Jmid, Iend, Jend)){
            root->bottomRight = new Node(arr[Imid][Jmid], true);

        }
        else{
            root->bottomRight = tree(arr, Imid, Jmid, Iend, Jend);
        }
        return root;

    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1){
            return new Node((bool)grid[0][0], true);
        } 
            
        if(valid(grid, 0, 0, n, n)){
            return new Node((bool)grid[0][0], true);
        }
        return tree(grid, 0, 0, n, n);
    }
};