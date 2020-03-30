class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        for(int i = 1;i<=rowIndex+1;i++){
            res[0] = 1;
            res[i-1] = 1;
            for(int j = i-2;j>=1;j--)
                res[j] = res[j]+res[j-1];
        }
        return res;
    }
};