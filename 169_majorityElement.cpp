class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 1,last = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]!=last){
                if(c == 1)
                    last = nums[i];
                else
                    c--;
            }else{
                c++;
            }
        }
        return last;
    }
};