class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0)
            return s.size();
        if(s.size() == 1)
            return s[0]-'0'>0&&s[0]-'0'<=26?1:0;
        int dp[s.size()+1];
        dp[0] = 1;
        for(int i = 1;i<=s.size();i++){
            dp[i] = 0;
            if(s[i-1]-'0'>0&&s[i-1]-'0'<=26)
                dp[i] += dp[i-1];
            if(i>=2){
                int code = atoi(s.substr(i-2,2));
                if(code<=26&&code>=10)
                    dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
    int atoi(string s){
        int res = 0;
        for(int i = 0;i<s.size();i++){
            res*=10;
            res+=s[i]-'0';
        }
        return res;
    }
};