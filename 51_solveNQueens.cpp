class Solution {
public:
    vector<vector<string>> res;
    vector<string> solution;
    vector<int> location;
    vector<int> column;
    string getLine(int index,int n){
        string res = "";
        for(int i = 0;i<n;i++){
            if(i == index)
                res+='Q';
            else
                res+='.';
        }
        return res;
    }
    bool checkValid(int i,int n){
        if(column[i] == 1)
            return false;
        for(int j = n-1;j>=0;j--){
            if(location[j] == i-(n-j)||location[j] == i+(n-j))
                return false;
        }
        return true;
    }
    void dfs(int n,int maxn){
        if(n==maxn){
            res.push_back(solution);
            return;
        }
        for(int i = 0;i<maxn;i++){
            if(checkValid(i,n)){
                solution.push_back(getLine(i,maxn));
                location.push_back(i);
                column[i] = 1;
                dfs(n+1,maxn);
                solution.pop_back();
                location.pop_back();
                column[i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0;i<n;i++)
            column.push_back(0);
            dfs(0,n);
        return res;
    }
};