class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        int i;
        for(i = 0;i<strs[0].size()&&i<strs[1].size();i++){
            if(strs[0][i] != strs[1][i])
                break;
        }
        for(int j = 2;j<strs.size();j++){
            int k;
            for(k = 0;k<i;k++){
                if(strs[j][k]!=strs[0][k])
                    break;
            }
            i = k;
            if(k == 0)
                return "";
        }
        return strs[0].substr(0,i);
    }
};
