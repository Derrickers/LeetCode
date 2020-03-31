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
    int res = 0;
    void dfs(TreeNode* root,int tmpsum){
        if(root->left == NULL&&root->right == NULL){
            res=res+tmpsum+root->val;
            return ;
        }
        tmpsum+=root->val;
        if(root->left!=NULL){
            dfs(root->left,tmpsum*10);
        }
        if(root->right!=NULL){
            dfs(root->right,tmpsum*10);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root != NULL)
            dfs(root,0);
        return res;
    }
};