class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, buy=prices[0];

        for(int i=1; i<prices.size(); i++){
            int currProfit = prices[i] - buy;
            if(prices[i] < buy){
                buy = prices[i];
            }else if(currProfit > maxProfit){
                maxProfit = currProfit;
            }
        }

        return maxProfit;
    }
};