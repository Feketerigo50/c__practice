/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        unordered_map<Node*, Node*> mapping;
        queue<Node*> que;
        mapping[head] = new Node(head->val);
        que.push(head);

        while(!que.empty()){
            Node* cur_node = que.front();
            que.pop();
            if(cur_node->next){
                if(!mapping.count(cur_node->next)){
                    mapping[cur_node->next] = new Node(cur_node->next->val);
                    que.push(cur_node->next);
                }
                mapping[cur_node]->next = mapping[cur_node->next];
            }
            if(cur_node->random){
                if(!mapping.count(cur_node->random)){
                    mapping[cur_node->random] = new Node(cur_node->random->val);
                    que.push(cur_node->random);
                }
                mapping[cur_node]->random = mapping[cur_node->random];
            }
        }
        
        return mapping[head];
    }
};