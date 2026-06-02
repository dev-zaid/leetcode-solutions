class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0], maxProfit = 0;

        for(int i=0; i<prices.size(); i++){
            int p = prices[i];

            if(p > bestBuy){
                maxProfit = max(maxProfit, p-bestBuy);
            }

            bestBuy = min(bestBuy, p);
        }

        return maxProfit;
    }
};