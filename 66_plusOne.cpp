class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int flag = 0;
        for(int i = digits.size()-1;i>=0;i--){
            int tmp;
            if(i == digits.size()-1){
                tmp = digits[i]+1;
            }else{
                tmp = digits[i]+flag;
            }
            flag = tmp>=10?1:0;
            tmp = tmp%10;
            res.push_back(tmp);
        }
        if(flag == 1)
            res.push_back(1);
        reverse(begin(res),end(res));
        return res;
    }
};