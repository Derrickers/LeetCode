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
解法1:两次遍历
**/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(!s.empty()||p!=NULL){
            if(p!=NULL){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                res.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        if(res.size()<=1)
            return true;
        for(int i = 0;i<res.size()-1;i++){
            if(res[i+1]<=res[i])
                return false;
        }
        return true;
    }
};

/**
解法2:一次遍历
**/