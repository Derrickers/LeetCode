class Solution {
public:
    int stringToInt(string s){
        int num = 0;
        for(int i = 0;i<s.size();i++){
            num*=10;
            num+=s[i]-'0';
        }
        return num;
    }
    int compareVersion(string version1, string version2) {
        int i = 0,j = 0;
        int len1 = version1.size(),len2=version2.size();
        int v1,v2;
        while(i<len1||j<len2){
            string s1="",s2="";
            while(i<len1&&version1[i]!='.'){
                s1+=version1[i++];
            }
            while(j<len2&&version2[j]!='.'){
                s2+=version2[j++];
            }
            i++;
            j++;
            v1 = stringToInt(s1);
            v2 = stringToInt(s2);
            if(v1>v2)
                return 1;
            if(v1<v2)
                return -1;
        }
        return 0;
    }
};