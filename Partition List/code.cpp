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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;

        ListNode front(0);
        ListNode* front_ptr = &front;
        ListNode back(0);
        ListNode* back_ptr = &back;

        while(head){
            if(head->val < x){
                front_ptr->next = head;
                front_ptr = front_ptr->next;
            }else{
                back_ptr->next = head;
                back_ptr = back_ptr->next;
            }
            head = head->next;
        }
        back_ptr->next = nullptr;
        
        front_ptr->next = back.next;
        
        return front.next;
    }
};