class Solution {
public:
    int calc(int n){
        int res = 0;
        while(n!=0){
            res+=pow(n%10,2);
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        int fast = calc(n),slow = n;
        while(fast!=1&&fast!=slow){
            slow = calc(slow);
            fast = calc(fast);
            if(fast == 1)
                return true;
            fast = calc(fast);
        }
        if(fast == 1)
            return true;
        return false;
    }
};