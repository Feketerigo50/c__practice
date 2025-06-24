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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        queue<ListNode*> que;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            que.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow){
            stk.push(slow);
            slow = slow->next;
        }

        ListNode dummy(0);
        ListNode *result = &dummy;
        
        while(!que.empty()){
            result->next = que.front();
            que.pop();
            result = result->next;
            if(!stk.empty()){
                result->next = stk.top();
                stk.pop();
                result = result->next;
            }
        }
        if(!stk.empty()){
            result->next = stk.top();
            stk.pop();
            result = result->next;
        }
        result->next = nullptr;

        return;
    }
};