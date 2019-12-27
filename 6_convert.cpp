/**
 *@author:Derricker
 *@date:2019/12/26
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int vnum = numRows*2-2,tmpvnum;
        string res;
        int ind = 0;
        for(int i = numRows;i>0;i--){
            ind = numRows-i;
            tmpvnum = 2*i-2;
            while(ind<s.size()){
                res+=s[ind];
                if(i!=1&&i!=numRows&&ind+tmpvnum<s.size())
                    res+=s[ind+tmpvnum];
                ind+=vnum;
            }
        }
        return res;
    }
};
