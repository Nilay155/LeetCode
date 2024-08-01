class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int buy = prices[0];
        int sell = prices[0];

        int profit = sell - buy;

        for(int i = 1 ; i < n ; i++) {
            sell = prices[i];

            if(sell - buy >= 0) {
                profit += sell - buy;
            }
            buy = sell;
        }
        return profit;
    }
};