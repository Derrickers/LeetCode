class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> alph,alphr;
        int len = s.size();
        for(int i = 0;i<len;i++){
            if(alph.find(s[i]) == alph.end()){
                if(alphr.find(t[i])!=alphr.end())
                    return false;
                alph.insert(pair<char,char>(s[i],t[i]));
                alphr.insert(pair<char,char>(t[i],s[i]));
            }else if(alph.find(s[i])->second!=t[i])
                return false;
        }
        return true;
    }
};