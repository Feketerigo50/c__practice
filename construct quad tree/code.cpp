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
    vector<vector<int>> map;

    Node* construct(vector<vector<int>>& grid) {
        this->map = grid;
        int n = grid.size();

        return build(0, 0, n);
    }

    bool needDivide(int st_x, int st_y, int step){
        int val = this->map[st_x][st_y];
        for(int i = st_x; i < st_x + step; i++){
            for(int j = st_y; j < st_y + step; j++){
                if(this->map[i][j] != val){
                    return true;
                }
            }
        }

        return false;
    }

    Node* build(int st_x, int st_y, int gridsize){
        if(!needDivide(st_x, st_y, gridsize)){
            return new Node(this->map[st_x][st_y], true);
        }

        
        int mid = gridsize / 2;
        Node* root = new Node(false, false);
        root->topLeft = build(st_x, st_y, mid);
        root->topRight = build(st_x, st_y + mid, mid);
        root->bottomLeft = build(st_x + mid, st_y, mid);
        root->bottomRight = build(st_x + mid, st_y + mid, mid);

        return root;
    }
};