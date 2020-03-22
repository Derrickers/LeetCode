class Solution {
public:
    int res = 0;
    vector<int> location;
    vector<int> column;
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
            res++;
            return;
        }
        for(int i = 0;i<maxn;i++){
            if(checkValid(i,n)){
                location.push_back(i);
                column[i] = 1;
                dfs(n+1,maxn);
                location.pop_back();
                column[i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        for(int i = 0;i<n;i++)
            column.push_back(0);
            dfs(0,n);
        return res;
    }
};