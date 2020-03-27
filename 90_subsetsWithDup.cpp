class Solution {
public:
    vector<vector<int>> res;
    vector<int> row;
    void dfs(vector<int>& nums,int index){
        res.push_back(row);
        if(index == nums.size())
            return;
        int last = nums[index]-1;
        for(int i = index;i<nums.size();i++){
            if(nums[i] == last)
                continue;
            else{
                last = nums[i];
                row.push_back(last);
                dfs(nums,i+1);
                row.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        dfs(nums,0);
        return res;
    }
};