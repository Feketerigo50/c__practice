/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) return "";

        Stack<TreeNode> stk = new Stack<>();
        TreeNode dummy = root;
        stk.push(root);

        StringBuilder preorder = new StringBuilder();
        while(!stk.isEmpty()){
            dummy = stk.pop();
            preorder.append(dummy.val);
            preorder.append(",");

            if(dummy.right != null) stk.push(dummy.right);
            if(dummy.left != null) stk.push(dummy.left);
        }

        preorder.setLength(preorder.length() - 1);
        return preorder.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.isEmpty()) return null;
        Queue<Integer> que = new LinkedList<>();
        for(String s : data.split(",")){
            if(!s.isEmpty()) que.offer(Integer.parseInt(s));
        }

        return makeTree(que, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private TreeNode makeTree(Queue<Integer> que, Integer lower, Integer upper){
        if(que.isEmpty()) return null;
        int val = que.peek();
        if(val < lower || val > upper) return null;

        val = que.poll();
        TreeNode root = new TreeNode(val);
        root.left = makeTree(que, lower, val);
        root.right = makeTree(que, val, upper);

        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;