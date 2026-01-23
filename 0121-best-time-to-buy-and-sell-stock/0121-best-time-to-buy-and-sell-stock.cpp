class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, l=0, r=1;
        
        while (r < prices.size()){
            int buy = prices[l], sell = prices[r];
            if(sell > buy){
                maxProfit = max(maxProfit, sell-buy);
            }

            else{
                l=r;
            }

            r++;
        }

        return maxProfit;
    }
};