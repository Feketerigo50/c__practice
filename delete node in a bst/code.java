/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;

        int val = root.val;
        if(key < val){
            root.left = deleteNode(root.left, key);
        }else if(key > val){
            root.right = deleteNode(root.right, key);
        }else{
            if(root.left == null) return root.right;
            if(root.right == null) return root.left;

            TreeNode cur = root.right;
            while(cur.left != null){
                cur = cur.left;
            }
            int next_key = cur.val;
            root.val = next_key;
            root.right = deleteNode(root.right, next_key);
        }

        return root;
    }
}