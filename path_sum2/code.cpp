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
    vector<vector<int>> result;

    void dfs(TreeNode* node, int cur_sum, vector<int> &path){
        if(!node) return;

        path.push_back(node->val);
        if(!node->left && !node->right && cur_sum == node->val){
            result.push_back(path);
        }

        dfs(node->left, cur_sum - node->val, path);
        dfs(node->right, cur_sum - node->val, path);

        path.pop_back();

        return;
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;

        dfs(root, targetSum, path);

        return result;
    }
};