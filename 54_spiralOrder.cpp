class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(),n = (m == 0)?0:matrix[0].size();
        if(m == 1)
            return matrix[0];
        if(n == 1){
            for(int i = 0;i<m;i++)
                res.push_back(matrix[i][0]);
            return res;
        } 
        int circ = min(m,n)-1;
        for(int i = 0;i<circ;i++){
            for(int j = i;j<n-i;j++)
                res.push_back(matrix[i][j]);
            for(int j = i+1;j<m-i;j++)
                res.push_back(matrix[j][n-i-1]);
            for(int j = n-i-2;j>i-1&&m-i-1>i;j--)
                res.push_back(matrix[m-i-1][j]);
            for(int j = m-i-2;j>i&&i<n-i-1;j--)
                res.push_back(matrix[j][i]);
        }
        return res;
    }
};