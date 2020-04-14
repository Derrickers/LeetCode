class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return 0;
        int isP[n];
        int res = 0;
        for(int i = 2;i<n;i++){
            isP[i] = 1;
        }
        for(int i = 2;i<=sqrt(n);i++){
            int j = i+i;
            while(j<n){
                isP[j] = 0;
                j+=i;
            }
        }
        for(int i = 2;i<n;i++){
            if(isP[i])
                res++;
        }
        return res;
    }
};