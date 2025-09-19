/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;

        Node extra_root(1);
        Node* root = &extra_root;
        Node* dummy = &extra_root;

        stack<Node*> stk;
        stk.push(head);
        while(!stk.empty()){
            Node* cur_node = stk.top();
            stk.pop();
            
            if(cur_node->next) stk.push(cur_node->next);
            if(cur_node->child){
                stk.push(cur_node->child);
                cur_node->child = nullptr;
            }

            root->next = cur_node;
            cur_node->prev = root;
            root = root->next;
        }
        
        dummy->next->prev = nullptr;
        root->next = nullptr;
        
        return dummy->next;
    }
};