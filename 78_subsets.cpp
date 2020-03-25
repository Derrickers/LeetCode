class Solution {
public:
    vector<vector<int>> res;
    vector<int> row;
    void dfs(int index,vector<int>& nums){
        res.push_back(row);
        for(int i = index;i<nums.size();i++){
            row.push_back(nums[i]);
            dfs(i+1,nums);
            row.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return res;
    }
};