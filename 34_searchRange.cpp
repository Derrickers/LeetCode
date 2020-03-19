class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        bisearch(res,nums,target,0,nums.size()-1);
        if(res.size() == 0){
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
    void bisearch(vector<int>& res,vector<int>& nums,int target,int begin,int end){
        if(begin>end)
            return;
        int mid = (begin+end)/2;
        if(nums[mid] == target){
            if(mid-1<0||nums[mid-1]!=target){
                res.push_back(mid);
            }else{
                bisearch(res,nums,target,begin,mid-1);
            }
            if(mid+1>=nums.size()||nums[mid+1]!=target){
                res.push_back(mid);
            }else{
                bisearch(res,nums,target,mid+1,end);
            }
            return;
        }else if(nums[mid]>target){
            bisearch(res,nums,target,begin,mid-1);
        }else{
            bisearch(res,nums,target,mid+1,end);
        }
    }
};
