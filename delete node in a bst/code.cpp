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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        int val = root->val;
        if(key > val){
            root->right = deleteNode(root->right, key);
        }else if(key < val){
            root->left = deleteNode(root->left, key);
        }else{
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode* cur = root->right;
            while(cur->left){
                cur = cur->left;
            }
            int next_key = cur->val;
            root->val = next_key;
            root->right = deleteNode(root->right, next_key);
        }

        return root;
    }
};