class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int minP = prices[0],maxP = 0;
        for(int p:prices){
            maxP = max(maxP,p-minP);
            minP = min(minP,p);
        }
        return maxP;
    }
};