class Solution {
public:
    vector<vector<int>> res;
    vector<int> row;
    void dfs(vector<int>& candidates,int target,int index){
        if(target == 0){
            res.push_back(row);
            return;
        }
        for(int i = index;i<candidates.size();i++){
            if(candidates[i]<=target){
                row.push_back(candidates[i]);
                dfs(candidates,target-candidates[i],i);
                row.pop_back();
            }else{
                return;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        dfs(candidates,target,0);
        return res;
    }
};
