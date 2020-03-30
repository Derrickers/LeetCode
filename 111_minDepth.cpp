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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *last = q.back(),*p;
        int lev = 1;
        while(!q.empty()){
            p = q.front();
            q.pop();
            if(p->left == NULL&&p->right == NULL)
                return lev;
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right !=NULL)
                q.push(p->right);
            if(p == last){
                lev++;
                last = q.back();
            }
        }
        return lev;
    }
};