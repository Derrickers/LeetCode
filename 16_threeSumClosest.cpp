class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mind = INT_MAX,res,tmps,tmpd,ind = 0;
        int begin,end;
        while(ind<nums.size()-2&&nums[ind]-target<mind){
            tmps = nums[ind];
            begin = ind+1;
            end = nums.size()-1;
            while(begin<end){
                tmps+=nums[begin]+nums[end];
                tmpd = abs(target-tmps);
                if(tmpd<mind){
                    if(tmpd == 0)
                        return tmps;
                    mind = tmpd;
                    res = tmps;
                }
                if(tmps<target){
                    begin++;
                    while(nums[begin] == nums[begin-1]&&begin<end)
                        begin++;
                }else{
                    end--;
                    while(nums[end] == nums[end+1]&&begin<end)
                        end--;
                }
                tmps = nums[ind];
            }
            ind++;
        }
        return res;
    }
};
