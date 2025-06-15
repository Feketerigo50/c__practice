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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> unique_trees;
        if(n == 0) return unique_trees;

        return trace(1,n);
    }

    vector<TreeNode*> trace(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(nullptr);
            return result;
        }

        for(int pick_root = start; pick_root <= end; pick_root++){
            vector<TreeNode*> left = trace(start, pick_root - 1);
            vector<TreeNode*> right = trace(pick_root + 1, end);

            for(auto l : left){
                for(auto r : right){
                    TreeNode* cur_root = new TreeNode(pick_root);
                    cur_root->left = l;
                    cur_root->right = r;
                    result.push_back(cur_root); 
                }
            }
        }


        return result;
    }
};