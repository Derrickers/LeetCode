class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n!=0){
            if(n%26!=0){
                res = (char)(n%26-1+'A')+res;
                n/=26;
            }else{
                res = 'Z'+res;
                n = n/26-1;
            }
        }
        return res;
    }
};