/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> stk;
    
    void push_left(TreeNode* node){
        while(node){
            stk.push(node);
            node = node->left;
        }
        return;
    }
public:
    BSTIterator(TreeNode* root) {
        push_left(root);
    }
    
    int next() {
        TreeNode* result;
        result = stk.top();
        stk.pop();
        if(result->right){
            push_left(result->right);
        }
        return result->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */