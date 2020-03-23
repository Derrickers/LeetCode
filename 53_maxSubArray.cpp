/**
两种解法：
解法1:在线处理
**/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int tmpsum = 0;
        for(int i = 0;i<nums.size();i++){
            tmpsum+=nums[i];
            if(tmpsum>maxsum)
                maxsum = tmpsum;
            if(tmpsum < 0)
                tmpsum = 0;
        }
        return maxsum;
    }
};
/**
解法2:分治法
**/
class Solution {
public:
    int div(int begin,int end,vector<int>& nums){
        if(begin == end)
            return nums[begin];
        int mid = (begin+end)/2;
        int crosssum;
        int leftsum = 0;
        int leftmaxsum = nums[mid];
        int rightsum = 0;
        int rightmaxsum = nums[mid+1];
        for(int i = mid;i>=begin;i--){
            leftsum += nums[i];
            if(leftsum>leftmaxsum)
                leftmaxsum = leftsum;
        }
        for(int i = mid+1;i<=end;i++){
            rightsum+=nums[i];
            if(rightsum>rightmaxsum)
                rightmaxsum = rightsum;
        }
        crosssum = leftmaxsum+rightmaxsum;
        return max(max(div(begin,mid,nums),div(mid+1,end,nums)),crosssum);
    }
    int maxSubArray(vector<int>& nums) {
        return div(0,nums.size()-1,nums);
    }
};