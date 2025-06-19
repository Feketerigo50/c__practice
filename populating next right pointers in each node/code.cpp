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
        
        Node* left_start = root->left;
        Node* right_start = root->right;
        while(left_start){
            left_start->next = right_start;
            left_start = left_start->right;
            right_start = right_start->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};