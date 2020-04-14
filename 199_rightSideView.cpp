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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == NULL)
            return res;
        TreeNode *last = root,*p;
        q.push(root);
        while(!q.empty()){
            p = q.front();
            q.pop();
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
            if(p == last){
                last = q.back();
                res.push_back(p->val);
            }
        }
        return res;
    }
};