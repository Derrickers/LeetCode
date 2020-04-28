/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    List<String> res = new ArrayList<>();
    String row = "";
    public List<String> binaryTreePaths(TreeNode root) {
        dfs(root);
        return res;
    }
    public void dfs(TreeNode root){
        if(root == null)
            return;
        if(root.left == null&&root.right == null) {
            row += root.val;
            res.add(new String(row));
            return;
        }
        row+=root.val+"->";
        String tmp = row;
        dfs(root.left);
        row = tmp;
        dfs(root.right);
    }
}