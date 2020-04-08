class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int b = 0,e = nums.size()-1,mid;
        while(b<e){
            mid = (b+e)/2;
            if(nums[mid]>nums[mid+1])
                e= mid;
            else
                b = mid+1;
        }
        return b;
    }
};