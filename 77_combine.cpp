class Solution {
public:
    vector<vector<int>> res;
    vector<int> row;
    void dfs(int index,int n, int k){
        if(row.size() == k){
            res.push_back(row);
            return;
        }
        for(int i = index+1;i<=n;i++){
            row.push_back(i);
            dfs(i,n,k);
            row.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(0,n,k);
        return res;
    }
};