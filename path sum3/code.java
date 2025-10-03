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
    private int target;
    private int result;
    private Map<Long, Integer> path;

    private void dfs(TreeNode root, long curSum){
        if(root == null) return;

        curSum += root.val;

        result += path.getOrDefault(curSum - target, 0);
        path.put(curSum, path.getOrDefault(curSum, 0) + 1);

        dfs(root.left, curSum);
        dfs(root.right, curSum);

        path.put(curSum, path.get(curSum) - 1);

        return;
    }

    public int pathSum(TreeNode root, int targetSum) {
        target = targetSum;
        result = 0;
        path = new HashMap<>();
        path.put(0L, 1);

        dfs(root, 0);

        return result;
    }
}