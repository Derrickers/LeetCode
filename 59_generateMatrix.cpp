class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n);
        vector<int> row(n);
        for(int i = 0;i<n;i++)
            res[i] = row;
        int num = 1,circ = n%2?n/2+1:n/2;
        for(int i = 0;i<circ;i++){
            for(int j = i;j<n-i;j++)
                res[i][j] = num++;
            for(int j = i+1;j<n-i;j++)
                res[j][n-i-1] = num++;
            if(i<n-i-1){
                for(int j = n-i-2;j>i-1;j--)
                    res[n-i-1][j] = num++;
                for(int j = n-i-2;j>i;j--)
                    res[j][i] = num++;
            }
        }
        return res;
    }
};