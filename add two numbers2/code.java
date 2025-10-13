/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<ListNode> stk1 = new Stack<>();
        while(l1 != null){
            stk1.push(l1);
            l1 = l1.next;
        }

        Stack<ListNode> stk2 = new Stack<>();
        while(l2 != null){
            stk2.push(l2);
            l2 = l2.next;
        }

        int carry = 0;
        ListNode result = null;
        while(!stk1.isEmpty() || !stk2.isEmpty() || carry == 1){
            int num = 0;
            if(!stk1.isEmpty()){
                num = stk1.pop().val;
            }
            
            int num2 = 0;
            if(!stk2.isEmpty()){
                num2 = stk2.pop().val;
            }

            num = num + num2 + carry;
            carry = num / 10;
            num %= 10;

            ListNode cur_node = new ListNode(num);
            cur_node.next = result;
            result = cur_node;
        }

        return result;
    }
}