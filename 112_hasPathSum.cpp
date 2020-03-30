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
    bool dfs(TreeNode* root,int sum){
        if(root == NULL)
            return false;
        int rem = sum-root->val;
        if(rem == 0&&root->left ==NULL&&root->right == NULL){
            return true;
        }
        return dfs(root->left,rem)||dfs(root->right,rem);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root,sum);
    }
};