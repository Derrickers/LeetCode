class Solution {
public:
    vector<vector<int>> res;
    vector<int> row;
    vector<int> flag;
    void dfs(vector<int>& nums){
        if(row.size() == nums.size()){
            res.push_back(row);
            return;
        }
        int last = nums[0]-1;
        for(int i = 0;i<nums.size();i++){
            if(flag[i] == 1||nums[i] == last)
                continue;
            last = nums[i];
            flag[i] = 1;
            row.push_back(nums[i]);
            dfs(nums);
            row.pop_back();
            flag[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        for(int i = 0;i<nums.size();i++)
            flag.push_back(0);
        dfs(nums);
        return res;
    }
};
