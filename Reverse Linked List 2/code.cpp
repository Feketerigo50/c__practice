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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        vector<ListNode*> stk;
        ListNode front(0);
        ListNode* fptr = &front;
        fptr->next = head;
        ListNode* step = &front;

        int deep = 0;
        while(deep <= right && step){
            if(deep == left-1){
                fptr = step;
            }
            if(deep >= left && deep <= right){
                stk.push_back(step);
            }
            step = step->next;
            deep++;
        }
        
        if(left == 1) head = stk.back();
        fptr->next = stk.back();
        fptr = stk.back()->next;
        step = stk.back();
        stk.pop_back();
        for(int i = stk.size(); i > 0; i--){
            step->next = stk.back();
            step = stk.back();
            stk.pop_back();
        }
        step->next = fptr;

        return head;
    }
};