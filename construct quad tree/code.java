/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}
*/

class Solution {
    private int[][] map;

    public Node construct(int[][] grid) {
        this.map = grid;
        return build(0, 0, grid.length);    
    }

    private boolean needDivide(int st_x, int st_y, int step){
        int val = this.map[st_x][st_y];
        for(int i = st_x; i < st_x + step; i++){
            for(int j = st_y; j < st_y + step; j++){
                if(this.map[i][j] != val){
                    return true;
                }
            }
        }

        return false;
    }

    private Node build(int st_x, int st_y, int gridsize){
        if(!needDivide(st_x, st_y, gridsize)){
            return new Node(this.map[st_x][st_y] == 1, true);
        }

        int mid = gridsize / 2;
        Node root = new Node(false, false);
        root.topLeft = build(st_x, st_y, mid);
        root.topRight = build(st_x, st_y + mid, mid);
        root.bottomLeft = build(st_x + mid, st_y, mid);
        root.bottomRight = build(st_x + mid, st_y + mid, mid);

        return root;
    }
}