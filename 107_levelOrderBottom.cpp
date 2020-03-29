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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        vector<int> row;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *last = q.back(),*p;
        while(!q.empty()){
            p = q.front();
            q.pop();
            row.push_back(p->val);
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right !=NULL)
                q.push(p->right);
            if(p == last){
                res.push_back(row);
                row.clear();
                last = q.back();
            }
        }
        reverse(begin(res),end(res));
        return res;
    }
};