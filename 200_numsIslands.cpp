class Solution {
public:
    int m,n;
    void alterIsland(int i,int j,vector<vector<char>>& grid){
        if(i<0||i>=m||j<0||j>=n)
            return;
        if(grid[i][j]!='1')
            return;
        grid[i][j] = '2';
        alterIsland(i-1,j,grid);
        alterIsland(i,j-1,grid);
        alterIsland(i+1,j,grid);
        alterIsland(i,j+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    alterIsland(i,j,grid);
                    res++;
                }
            }
        }
        return res;
    }
};