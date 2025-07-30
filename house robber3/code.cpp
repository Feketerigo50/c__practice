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
    pair<int, int> treeRob(TreeNode* node){
        if(!node) return {0,0};

        auto [leftrob, leftnot] = treeRob(node->left);
        auto [rightrob, rightnot] = treeRob(node->right);

        int robthis = node->val + leftnot + rightnot;
        int robnot = max(leftrob, leftnot) + max(rightrob, rightnot);

        return {robthis, robnot};
    }
    int rob(TreeNode* root) {
        auto [robthis, robnot] = treeRob(root);
        return max(robthis, robnot);
    }
};