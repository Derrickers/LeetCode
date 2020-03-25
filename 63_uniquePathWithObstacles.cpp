class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        long dp[m][n];
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else if(i == 0&&j == 0){
                    dp[i][j] = 1;
                }else{
                    long down = i-1<0?0:dp[i-1][j];
                    long right = j-1<0?0:dp[i][j-1];
                    dp[i][j] = down+right;
                }
            }
        }
        return dp[m-1][n-1];
    }
};