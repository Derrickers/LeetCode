class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int b = 0,e = 0;
        int minl = INT_MAX;
        while(e<nums.size()){
            sum+=nums[e++];
            if(sum<=0){
                b = e;
                sum = 0;
            }
            if(sum>=s){
                while(sum-nums[b]>=s){
                    sum-=nums[b];
                    b++;
                }
                if(e-b<minl)
                    minl = e-b;
            }
        }
        return minl==INT_MAX?0:minl;
    }
};