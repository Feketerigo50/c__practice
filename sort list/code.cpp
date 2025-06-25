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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        int len = 0;
        ListNode* node = head;
        while(node){
            len++;
            node = node->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        for(int step = 1; step < len; step *= 2){
            ListNode* prev = &dummy;
            ListNode* cur = prev->next;

            while(cur){
                ListNode* left = cur;
                ListNode* right = split(left, step);
                cur = split(right, step);

                prev = merge(left, right, prev);
            }
        }
        
        return dummy.next;
    }

    ListNode* split(ListNode* start, int step){
        int move = 0;
        ListNode* prev;
        while(start && move < step){
            prev = start;
            start = start->next;
            move++;
        }
        if(!start) return nullptr;
        
        prev->next = nullptr;
        return start;
    }

    ListNode* merge(ListNode* left, ListNode* right, ListNode* prev){
        ListNode* cur = prev;

        while(left && right){
            if(left->val <= right->val){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left ? left : right;
        while(cur->next){
            cur = cur->next;
        }

        return cur;
    }
};