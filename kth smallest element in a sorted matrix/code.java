class Node{
    int val;
    int row;
    int col;

    Node(int val, int row, int col){
        this.val = val;
        this.row = row;
        this.col = col;
    }
}

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Node> minHeap = new PriorityQueue<>(
          (a, b) -> Integer.compare(a.val, b.val)  
        );

        int n = matrix.length;

        for(int i = 0; i < n; i++){
            minHeap.offer(new Node(matrix[i][0], i, 0));
        }

        int counter = 0;
        while(!minHeap.isEmpty()){
            Node minNode = minHeap.poll();
            counter++;
            if(counter == k) return minNode.val;
            if(minNode.col + 1 < n){
                minHeap.offer(new Node(matrix[minNode.row][minNode.col + 1], minNode.row, minNode.col + 1));
            }
        }

        return -1;
    }
}