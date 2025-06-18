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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        stack <TreeNode*> stk0;
        stack <TreeNode*> stk1;
        stk0.push(root);

        TreeNode* cur_node;
        vector<int> tmp;

        while(!stk0.empty() || !stk1.empty()){
            while(!stk0.empty()){
                cur_node = stk0.top();
                stk0.pop();
                tmp.push_back(cur_node->val);
                if(cur_node->left) stk1.push(cur_node->left);
                if(cur_node->right) stk1.push(cur_node->right);
            }
            if(!tmp.empty()){
                result.push_back(tmp);
                tmp.clear();
            }
            while(!stk1.empty()){
                cur_node = stk1.top();
                stk1.pop();
                tmp.push_back(cur_node->val);
                if(cur_node->right) stk0.push(cur_node->right);
                if(cur_node->left) stk0.push(cur_node->left);
            }
            if(!tmp.empty()){
                result.push_back(tmp);
                tmp.clear();
            }
        }

        return result;
    }
};