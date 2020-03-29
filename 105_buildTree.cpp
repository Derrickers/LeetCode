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
    int findIndex(int b,int e,int val,vector<int>& inorder){
        for(int i = b;i<=e;i++)
            if(inorder[i] == val)
                return i;
        return 0;
    }
    TreeNode* build(int b1,int e1,int b2,int e2,vector<int>& preorder, vector<int>& inorder){
        if(b1 > e1)
            return NULL;
        int rval = preorder[b1];
        TreeNode *root = new TreeNode(rval);
        if(b1 == e1)
            return root;
        int mid = findIndex(b2,e2,rval,inorder);
        root->left = build(b1+1,b1+mid-b2,b2,mid-1,preorder,inorder);
        root->right = build(b1+mid-b2+1,e1,mid+1,e2,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }
};