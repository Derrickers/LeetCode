class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<2)
            return 0;
        int stack[s.size()+1];
        int top = 0;
        int maxlength = 0;
        //哨兵
        stack[top++] = -1;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                stack[top++] = i;
            }else{
                top--;
                if(top == 0){
                    stack[top++] = i;
                }else{
                    maxlength = maxlength>i-stack[top-1]?maxlength:(i-stack[top-1]);
                }
            }
        }
        return maxlength;
    }
};
