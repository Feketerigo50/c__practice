/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> level_order = new ArrayList<>();
        if(root == null) return level_order;

        Queue<Node> que = new LinkedList<>();
        que.offer(root);
        while(que.size() != 0){
            List<Integer> element = new ArrayList<>();
            int level_count = que.size();

            for(int i = 0; i < level_count; i++){
                Node cur_node = que.poll();
                element.add(cur_node.val);

                for(Node child : cur_node.children){
                    que.offer(child);
                }
            }

            level_order.add(element);
        }

        return level_order;
    }
}