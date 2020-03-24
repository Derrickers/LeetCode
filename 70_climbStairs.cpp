/**
动态规划：一个位置有两种可能：n-2走两级和n-1走一级
所以num[n] = num[n-2]+num[n-1];
转化为斐波那契数列
**/
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int a = 1,b = 2;
        for(int i = 2;i<n;i++){
            int tmp = a;
            a = b;
            b = tmp+b;
        }
        return b;
    }
};