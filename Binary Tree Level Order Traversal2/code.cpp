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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> que;
        int level = 1;
        vector<int> tmp;

        que.push(make_pair(root, level));

        while(root && !que.empty()){
            root = que.front().first;
            int cur_level = que.front().second;
            que.pop();

            if(cur_level != level){
                result.push_back(tmp);
                tmp.clear();
                level++;
            }
            tmp.push_back(root->val);

            if(root->left){
                que.push(make_pair(root->left, cur_level+1));
            }
            if(root->right){
                que.push(make_pair(root->right, cur_level+1));
            }
        }
        if(root)result.push_back(tmp);

        reverse(result.begin(),result.end());
        return result;
    }
};