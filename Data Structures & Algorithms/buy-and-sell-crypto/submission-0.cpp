class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int i=0; i<prices.size(); i++){
            int cost = prices[i] - minPrice;
            maxProfit = max(maxProfit, cost);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};
