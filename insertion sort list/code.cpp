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
    void insertNode(ListNode* front, ListNode* in){
        ListNode* tmp = front->next;
        front->next = in;
        in->next = tmp;

        return;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-6000);
        ListNode* prev;
        ListNode* next;
        dummy.next = head;
        head = head->next;
        dummy.next->next = nullptr;
        while(head){
            prev = &dummy;
            next = head->next;
            while(prev && prev->next){
                if(head->val > prev->val && head->val <= prev->next->val){
                    insertNode(prev, head);
                    break;
                }else{
                    prev = prev->next;
                }
            }
            if(!prev->next){
                insertNode(prev, head);
            }
            head = next;
        }

        return dummy.next;
    }
};