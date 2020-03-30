class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
            return res;
        vector<int> row(1);
        row[0] = 1;
        res.push_back(row);
        for(int i = 2;i<=numRows;i++){
            vector<int> row(i);
            row[0] = 1;
            row[i-1] = 1;
            for(int j = 1;j<i-1;j++)
                row[j] = res[i-2][j-1]+res[i-2][j];
            res.push_back(row);
        }
        return res;
    }
};