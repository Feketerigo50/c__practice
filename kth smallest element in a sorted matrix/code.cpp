class Solution {
public:
    struct Node{
        int val, row, col;
        bool operator>(const Node &other) const{
            return val > other.val;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node, vector<Node>, greater<Node>> min_heap;
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            min_heap.push({matrix[i][0], i, 0});
        }

        int counter = 0;
        while(!min_heap.empty()){
            Node cur = min_heap.top(); 
            min_heap.pop();

            counter++;
            if(counter == k) return cur.val;
            if(cur.col + 1 < n){
                min_heap.push({matrix[cur.row][cur.col+1], cur.row, cur.col+1});
            }
        }
        return -1;
    }
};