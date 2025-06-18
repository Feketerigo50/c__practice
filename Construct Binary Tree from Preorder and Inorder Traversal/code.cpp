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
    unordered_map<int, int> inorderIndexMap;

    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = inorderIndexMap[rootVal];
        int leftSize = rootIndex - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSize,
                                    inorder, inStart, rootIndex - 1);
        root->right = buildTreeHelper(preorder, preStart + leftSize + 1, preEnd,
                                    inorder, rootIndex + 1, inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndexMap[inorder[i]] = i;

        return buildTreeHelper(preorder, 0, preorder.size() - 1,
                               inorder, 0, inorder.size() - 1);
    }
};