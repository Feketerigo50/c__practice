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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        queue<pair<TreeNode*, int>> bfs;
        TreeNode* prev = root;
        int level = 1;
        bfs.push({root, 1});
        while(!bfs.empty()){
            TreeNode* cur_node = bfs.front().first;
            int cur_level = bfs.front().second;
            bfs.pop();

            if(cur_level != level){
                result.push_back(prev->val);
                level++;
            }
            if(cur_node->left) bfs.push({cur_node->left, cur_level+1});
            if(cur_node->right) bfs.push({cur_node->right, cur_level+1});
            prev = cur_node;
        }
        result.push_back(prev->val);

        return result;
    }
};