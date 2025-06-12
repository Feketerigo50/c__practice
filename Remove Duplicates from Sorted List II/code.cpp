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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode cut_point_head(0);
        cut_point_head.next = head;
        ListNode* cut_ptr = &cut_point_head;

        while(head){
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    head = head->next;
                }
                cut_ptr->next = head->next;
                head = head->next;
            }else{
                cut_ptr = head;
                head = head->next;
            }
        }


        return cut_point_head.next;
    }
};