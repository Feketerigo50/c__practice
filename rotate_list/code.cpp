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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        ListNode* result = head;
        ListNode* cut_point_front;
        ListNode* cut_point_back = head;
        int length = 0;
        while(head){
            length++;
            cut_point_front = head;
            head = head->next;
        }
        k = length - k % length;

        if(k != length){
            while(--k){
                cut_point_back = cut_point_back-> next;
            }
            cut_point_front->next = result;
            result = cut_point_back->next;
            cut_point_back->next = NULL;
        }

        return result;
    }
};