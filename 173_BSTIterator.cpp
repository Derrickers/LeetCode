/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> mins;
    BSTIterator(TreeNode* root) {
        while(root!=NULL){
            mins.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *p = mins.top(),*q = p->right;
        mins.pop();
        while(q!=NULL){
            mins.push(q);
            q = q->left;
        }
        return p->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mins.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */