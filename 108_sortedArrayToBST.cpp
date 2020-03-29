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
    TreeNode* build(int b,int e,vector<int>& nums){
        if(b>e)
            return NULL;
        int mid = (b+e)%2?(b+e)/2+1:(b+e)/2;
        TreeNode *r = new TreeNode(nums[mid]);
        if(b!=e){
            r->left = build(b,mid-1,nums);
            r->right = build(mid+1,e,nums);
        }
        return r;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0,nums.size()-1,nums);
    }
};