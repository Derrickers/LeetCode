class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        int bound = 0,newbound  = 0;
        int begin = 0;
        while(bound < nums.size()-1){
            for(int i = begin;i<=bound;i++)
                newbound = max(newbound,i+nums[i]);
            if(newbound == bound)
                return false;
            else
                begin = bound+1;
            bound = newbound;
        }
        return true;
    }
};