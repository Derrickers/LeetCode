class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0;i<nums.size();i++)
            s.insert(nums[i]);
        int res = 0;
        for(int num:s){
            int tmpl = 1;
            int tmp = num-1;
            while(s.count(tmp)){
                s.erase(tmp--);
                tmpl++;
            }
            tmp = num+1;
            while(s.count(tmp)){
                s.erase(tmp++);
                tmpl++;
            }
            res = max(res,tmpl);
        }
        return res;
    }
};