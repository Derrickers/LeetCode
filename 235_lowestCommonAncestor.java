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
        if(p.val>q.val){
            TreeNode tmp = p;
            p = q;
            q = tmp;
        }
        while(root!=p&&root!=q){
            if((root.val-p.val)*(root.val-q.val)<0){
                break;
            }
            if(root.val>q.val)
                root = root.left;
            if(root.val<p.val)
                root = root.right;
        }
        return root;
    }
}