class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long rev = 0,tmpx = x;
        while(tmpx!= 0){
            rev= rev*10+tmpx%10;
            tmpx/=10;
        }
        return (int)rev == x;
    }
};
