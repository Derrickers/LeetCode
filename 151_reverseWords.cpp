class Solution {
public:
    string reverseWords(string s) {
        string word;
        string res;
        int i = 0;
        int len = s.size();
        while(i<len){
            word="";
            while(i<len&&s[i] == ' ')
                i++;
            while(i<len&&s[i] != ' ')
                word+=s[i++];
            if(i>=len)
                res = word+res;
            else
                res = " "+word+res;
        }
        return res[0]==' '?res.substr(1,res.size()-1):res;
    }
};