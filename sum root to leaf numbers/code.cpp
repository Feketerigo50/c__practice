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

    void DFSrecursive(TreeNode* root, int cur_sum, int& total_sum){
        if(!root) return;
        cur_sum = cur_sum*10 + root->val;
        if(!root->left && !root->right){
            total_sum += cur_sum;
            return;
        }
        DFS(root->left, cur_sum, total_sum);
        DFS(root->right, cur_sum, total_sum);
        return;
    }

    void DFSiterative(TreeNode* root, int cur_sum, int& total_sum){
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, root->val});

        while(!stk.empty()){
            auto [root, cur_sum] = stk.top();
            stk.pop();

            if(!root->right && !root->left){
                total_sum += cur_sum;
            }

            if(root->left){
                stk.push({root->left, root->left->val + cur_sum*10});
            }
            if(root->right){
                stk.push({root->right, root->right->val + cur_sum*10});
            }
        }

        return;
    }

    int sumNumbers(TreeNode* root) {
        int result = 0;
        int cur_sum = 0;
        DFS(root, cur_sum, result);

        return result;
    }
};