class Solution {
public:
    vector<int> row;
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target,int index){
        if(target == 0){
            res.push_back(row);
            return;
        }
        int last = -1;
        for(int i = index;i<candidates.size();i++){
            if(candidates[i] == last)
                continue;
            else
                last = candidates[i];
            if(candidates[i]<=target){
                row.push_back(candidates[i]);
                dfs(candidates,target-candidates[i],i+1);
                row.pop_back();
            }else{
                return;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        dfs(candidates,target,0);
        return res;
    }
};
