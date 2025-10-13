/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;

        while(l1){
            stk1.push(l1);
            l1 = l1->next;
        }

        while(l2){
            stk2.push(l2);
            l2 = l2->next;
        }

        if(stk2.size() > stk1.size()){
            stk1.swap(stk2);
        }

        ListNode* result = nullptr;
        int carry = 0;
        while(!stk1.empty() || carry){
            int num = 0;
            if(!stk1.empty()){
                num = stk1.top()->val;
                stk1.pop();
            }
            
            int num2 = 0;
            if(!stk2.empty()){
                num2 = stk2.top()->val;
                stk2.pop();
            }
            
            num = num + num2 + carry;
            carry = num / 10;
            num %= 10;

            ListNode* cur_node = new ListNode(num);

            cur_node->next = result;
            result = cur_node;
        }

        return result;
    }
};