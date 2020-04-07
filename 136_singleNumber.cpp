class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size(),res = 0;
        if(len<2)
            return nums[0];
        for(int num:nums)
            res^=num;
        return res;
    }
};