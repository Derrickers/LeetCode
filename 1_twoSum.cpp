/**
 *@author:Derricker
 *@date:2019/12/23
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> alph;
        for(int i = 0;i<nums.size();i++){
            int sub = target-nums[i];
            if(alph.find(sub)!= alph.end()){
                int ind = alph.find(sub)->second;
                if(ind == i)
                    continue;
                res.push_back(ind);
                res.push_back(i);
                return res;
            }
            alph.insert(pair<int,int>(nums[i],i));
        }
        return res;
    }
};
