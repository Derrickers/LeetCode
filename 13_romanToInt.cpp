class Solution {
public:
    int romanToInt(string s) {
        int res = 0,ind = 0;
        while(s[ind] == 'M'&&ind<s.size()){
            res+=1000;
            ind++;
        }
        if(s[ind] == 'D'){
            res+=500;
            ind++;
        }else if(s[ind] == 'C'&&s[ind+1]=='M'){
            res+=900;
            ind+=2;
        }else if(s[ind] == 'C'&&s[ind+1] == 'D'){
            res+=400;
            ind+=2;
        }
        while(s[ind] == 'C'&&ind<s.size()){
            res+=100;
            ind++;
        }
        if(s[ind] == 'L'){
            res+=50;
            ind++;
        }else if(s[ind] == 'X'&&s[ind+1]=='C'){
            res+=90;
            ind+=2;
        }else if(s[ind] == 'X'&&s[ind+1] == 'L'){
            res+=40;
            ind+=2;
        }
        while(s[ind] == 'X'&&ind<s.size()){
            res+=10;
            ind++;
        }
        if(s[ind] == 'V'){
            res+=5;
            ind++;
        }else if(s[ind] == 'I'&&s[ind+1]=='X'){
            res+=9;
            ind+=2;
        }else if(s[ind] == 'I'&&s[ind+1] == 'V'){
            res+=4;
            ind+=2;
        }
        while(s[ind] == 'I'&&ind<s.size()){
            res+=1;
            ind++;
        }
        return res;
    }
};
