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
    int find(vector<int>& inorder,int b,int e,int t){
        for(int i = b;i<=e;i++)
            if(inorder[i] == t)
                return i;
        return 0;
    }
    TreeNode *build(int b1,int e1,int b2,int e2,vector<int>& inorder, vector<int>& postorder){
        if(b1>e1)
            return NULL;
        if(b1 == e1)
            return new TreeNode(postorder[b1]);
        int rval = postorder[e1];
        TreeNode *r = new TreeNode(postorder[e1]);
        int mid = find(inorder,b2,e2,rval);
        r->left = build(b1,b1+mid-b2-1,b2,mid-1,inorder,postorder);
        r->right = build(b1+mid-b2,e1-1,mid+1,e2,inorder,postorder);
        return r;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return build(0,size-1,0,size-1,inorder,postorder);
    }
};