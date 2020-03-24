class Solution {
public:
    string addBinary(string a, string b) {
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
        string res = "";
        int flag = 0;
        int i;
        for(i = 0;i<a.size()&&i<b.size();i++){
            if(flag == 0){
                if(a[i] == '1'&&b[i] == '1'){
                    flag = 1;
                    res+='0';
                }else if(a[i] == '0'&&b[i] == '0')
                    res+='0';
                else
                    res+='1';
            }else{
                if(a[i] == '1'&&b[i] == '1'){
                    res+='1';
                }else if(a[i] == '0'&&b[i] == '0'){
                    flag = 0;
                    res+='1';
                }else
                    res+='0';
            }
        }
        for(;i<a.size();i++){
            if(flag == 0){
                res+=a[i];
            }else{
                if(a[i] == '1')
                    res+='0';
                else{
                    res+='1';
                    flag = 0;
                }
            }
        }
        for(;i<b.size();i++){
            if(flag == 0){
                res+=b[i];
            }else{
                if(b[i] == '1')
                    res+='0';
                else{
                    res+='1';
                    flag = 0;
                }
            }
        }
        if(flag == 1)
            res+='1';
        reverse(begin(res),end(res));
        return res;
    }
};