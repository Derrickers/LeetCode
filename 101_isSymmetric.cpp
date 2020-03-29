/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /**
 递归解法
 **/
class Solution {
public:
    bool judge(TreeNode *p,TreeNode *q){
        if(p == NULL&&q == NULL)
            return true;
        if(p==NULL||q == NULL)
            return false;
        if(p->val != q->val)
            return false;
        return judge(p->left,q->right)&&judge(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return judge(root->left,root->right);
    }
};
/**
迭代解法
**/
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        que.push(root);
        TreeNode *p,*q;
        while(!que.empty()){
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();
            if(p == NULL&&q==NULL)
                continue;
            if(p == NULL||q == NULL)
                return false;
            if(p->val!=q->val)
                return false;
            que.push(p->left);
            que.push(q->right);
            que.push(p->right);
            que.push(q->left);
        }
        return true;
    }
};