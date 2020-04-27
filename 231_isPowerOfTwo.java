class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        while(n%2!=1){
            n = n/2;
        }
        if(n == 1)
            return true;
        return false;
    }
}