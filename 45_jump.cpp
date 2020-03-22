class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int time = 0;
        int start = 0;
        int farest = 0;
        while(farest<nums.size()-1){
            int maxindex = 0;
            for(int i = start;i<=farest;i++){
                maxindex = max(maxindex,i+nums[i]);
            }
            time++;
            start = farest+1;
            farest = maxindex;
        }
        return time;
    }
};
