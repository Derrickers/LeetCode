class Solution {
public:
    double myPow(double x, int n) {
        if(x == -1)
            return n%2?-1:1;
        long time = n;
        time = time<0?-time:time;
        return n<0?calc(1/x,time):calc(x,time);
    }
    double calc(double x,long n){
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        double part1 = calc(x,n/2);
        double part2 = calc(x,n%2);
        return part1*part1*part2;
    }
};
