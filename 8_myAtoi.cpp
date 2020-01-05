/*
 *@author:Derrciker
 *@date:2019/12/28
 */
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int ind = 0,flag = 1;
        while(str[ind] == ' ')ind++;
        if(str[ind] == '-'){
            flag = -1;
            ind++;
        }else if(str[ind] == '+'){
            ind++;
        }
        while(str[ind]<='9'&&str[ind]>='0'&&res<=INT_MAX){
            res = res*10+(str[ind++]-'0');
            if(res>INT_MAX&&flag == 1)
                return INT_MAX;
            else if(res*-1<INT_MIN&&flag == -1)
                return INT_MIN;
        }
        return res*flag;
    }
};
