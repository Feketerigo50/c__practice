/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node flatten(Node head) {
        if(head == null) return null;

        Stack<Node> stk = new Stack<>();
        stk.push(head);

        Node dummy = new Node(0);
        Node prev = dummy;

        while(!stk.isEmpty()){
            Node cur_node = stk.pop();

            if(cur_node.next != null) stk.push(cur_node.next);
            if(cur_node.child != null){
                stk.push(cur_node.child);
                cur_node.child = null;
            }

            prev.next = cur_node;
            cur_node.prev = prev;

            prev = cur_node;
        }

        dummy.next.prev = null;
        prev.next = null;

        return dummy.next;
    }
}