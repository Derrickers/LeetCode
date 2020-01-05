/**
 *@author:Derricker
 *@date:2019/12/26
 */
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x != 0){
            res*=10;
            res+=x%10;
            x/=10;
        }
        if((int)res != res){
            res = 0;
        }
        return (int)res;
    }
};
