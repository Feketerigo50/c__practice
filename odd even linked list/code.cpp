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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;

        ListNode even(0);
        ListNode* evenptr = &even;
        ListNode odd(0);
        ListNode* oddptr = &odd;

        bool flag = false;
        while(head){
            if(flag){
                evenptr->next = head;
                evenptr = evenptr->next;
            }else{
                oddptr->next = head;
                oddptr = oddptr->next;
            }
            head = head->next;
            flag = !flag;
        }
        oddptr->next = even.next;
        evenptr->next = nullptr;


        return odd.next;
    }
};