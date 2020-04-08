class Solution {
public:
    int stringToInt(string s){
        int flag = 1,i = 0;
        if(s[0] == '-'){
            flag = -1;
            i = 1;
        }
        int num = 0;
        for(;i<s.size();i++){
            num*=10;
            num+=s[i]-'0';
        }
        return num*flag;
    }
    int calcSig(string s){
        if(s == "+")
            return 1;
        if(s == "-")
            return 2;
        if(s == "*")
            return 3;
        if(s == "/")
            return 4;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int a,b;
        for(string s:tokens){
            int code = calcSig(s);
            if(code == 0)
                nums.push(stringToInt(s));
            else{
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                switch(code){
                    case 1:
                        nums.push(b+a);
                        break;
                    case 2:
                        nums.push(b-a);
                        break;
                    case 3:
                        nums.push(b*a);
                        break;
                    case 4:
                        nums.push(b/a);
                        break;    
                }
            }
        }
        return nums.top();
    }
};