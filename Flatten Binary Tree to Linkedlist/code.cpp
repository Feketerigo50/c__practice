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
class Solution {
public:
    queue<TreeNode*> que;
    
    void preorder(TreeNode* node){
        if(!node) return;

        que.push(node);
        
        preorder(node->left);
        preorder(node->right);

        return;
    }

    void flatten(TreeNode* root) {
        if(!root) return;
        preorder(root);
        que.pop();

        TreeNode* pre_node;
        pre_node = root;
        while(!que.empty()){
            pre_node->left = nullptr;
            pre_node->right = que.front();
            que.pop();
            pre_node = pre_node->right;
        }      
        
        return;
    }
};