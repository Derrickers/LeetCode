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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root!=NULL||!s.empty()){
            if(root!=NULL){
                res.push_back(root->val);
                s.push(root);
                root = root->left;
            }else{
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return res;
    }
};