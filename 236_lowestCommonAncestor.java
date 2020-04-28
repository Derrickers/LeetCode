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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        //结论0
        if (root == null || root == p || root == q)
            return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);

        //结论1
        if (left != null && left != q && left != p)
            return left;
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        //结论3
        if (left != null && right != null)
            return root;

        //结论2 4
        else
            return left == null ? right : left;
    }
}