/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* dummy;
        if(p->val < q->val){
            dummy = q;
            q = p;
            p = dummy;
        }

        dummy = root;
        while(dummy){
            if(p->val < dummy->val){
                dummy = dummy->left;
            }else if(q->val > dummy->val){
                dummy = dummy->right;
            }else{
                return dummy;
            }
        }

        return root;
    }
};