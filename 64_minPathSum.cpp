class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int dp[m][n];
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0&&j == 0)
                    dp[i][j] = grid[i][j];
                else{
                    int down = i-1<0?INT_MAX:dp[i-1][j];
                    int right = j-1<0?INT_MAX:dp[i][j-1];
                    dp[i][j] = min(down,right)+grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};