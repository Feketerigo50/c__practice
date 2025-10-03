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
private:
    int result;
    int target;

public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        
        result = 0;
        target = targetSum;
        auto t = treeSum(root);

        return result;
    }

    vector<long long> treeSum(TreeNode* root){
        vector<long long> posi_pathsum;
        posi_pathsum.push_back(root->val);
        if(root->val == target) result++;

        if(root->left){
            vector<long long> path_of_left = treeSum(root->left);
            for(int i = 0; i < path_of_left.size(); i++){
                long long tmp_sum = root->val + path_of_left[i];
                if(tmp_sum == target) result++;
                posi_pathsum.push_back(tmp_sum);
            }
        }
        
        if(root->right){
            vector<long long> path_of_right = treeSum(root->right);
            for(int i = 0; i < path_of_right.size(); i++){
                long long tmp_sum = root->val + path_of_right[i];
                if(tmp_sum == target) result++;
                posi_pathsum.push_back(tmp_sum);
            }
        }


        return posi_pathsum;
    }
};