/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        Node* cur_node = root;
        Node dummy(0);
        Node* tail = &dummy;

        while(cur_node){

            tail = &dummy;
            tail->next = nullptr;
            while(cur_node){
                
                if(cur_node->left){
                    tail->next = cur_node->left;
                    tail = tail->next;
                }

                if(cur_node->right){
                    tail->next = cur_node->right;
                    tail = tail->next;
                }
                cur_node = cur_node->next;
            }
            cur_node = dummy.next;
        }
        
        return root;
    }
};