/**
解法1：暴力穷举法
**/
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0||x == 1)
            return x;
        for(int i = 1;;i++)
            if(i<=x/i&&(i+1)>x/(i+1))
                return i;
    }
};
/**
解法二：二分查找法
**/
class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        int b = 1,e = x/2;
        while(b<=e){
            int m = (b+e)/2;
            if(m<=x/m&&(m+1)>x/(m+1))
                return m;
            else if((m+1)<=x/(m+1))
                b = m+1;
            else
                e = m-1;
        }
        return -1;
    }
};
/**
解法三：牛顿递推式法
**/
class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        double x0 = x;
        double x1 = (x0+x/x0)/2;
        double sub = (x1-x0)>=0?x1-x0:x0-x1;
        while(sub>=1){
            x0 = x1;
            x1 = (x0+x/x0)/2;
            sub = (x1-x0)>=0?x1-x0:x0-x1;
        }
        return x1;
    }
};