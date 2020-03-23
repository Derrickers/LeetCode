class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int lastlen = 0;
        for(int i = 0;i<s.size();){
            if(s[i] == ' '){
                lastlen = len;
                len = 0;
                while(i<s.size()&&s[i] == ' ')
                    i++;
                continue;
            }else{
                len++;
                i++;
            }
        }
        return len == 0?lastlen:len;
    }
};