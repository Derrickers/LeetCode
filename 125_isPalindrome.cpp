class Solution {
public:
    bool checkV(char &a){
        if(a<='Z'&&a>='A')
            a = a+32;
        return (a<='z'&&a>='a')||(a<='9'&&a>='0');
    }
    bool isPalindrome(string s) {
        int i = 0,j = s.size()-1;
        while(i<j){
            while(i<j&&!checkV(s[i]))
                i++;
            while(i<j&&!checkV(s[j]))
                j--;
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
};