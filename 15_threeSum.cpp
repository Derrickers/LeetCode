class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        int begin,end,last;
        for(int i = 0;nums[i]<=0&&i<nums.size()-2;i++){
            if(nums[i] == last&&i>=1){
                continue;
            }
            vector<int> tmp;
            begin = i+1;
            end = nums.size()-1;
            while(begin<end){
                if(nums[begin]+nums[end]+nums[i] == 0){
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[begin]);
                    tmp.push_back(nums[end]);
                    res.push_back(tmp);
                    tmp.clear();
                    begin++;
                    end--;
                    while(begin<end&&nums[begin] == nums[begin-1])
                        begin++;
                    while(end>begin&&nums[end]== nums[end+1])
                        end--;
                }else if(nums[begin]+nums[end]+nums[i] < 0){
                    begin++;
                }else
                    end--;
            }
            last = nums[i];
        }
        return res;
    }
};
