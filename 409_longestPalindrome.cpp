class Solution {
public:
    int longestPalindrome(string s) {
        int alph[128] = {0};
        int maxsize = 0;
        for(int i = 0;i<s.size();i++){
            if(alph[s[i]] == 0){
                alph[s[i]]++;
            }else{
                alph[s[i]] = 0;
                maxsize+=2;
            }
        }
        if(maxsize<s.size())
            maxsize++;
        return maxsize;
    }
};
