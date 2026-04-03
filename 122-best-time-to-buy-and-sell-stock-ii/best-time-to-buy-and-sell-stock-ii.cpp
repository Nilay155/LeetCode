class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], profit = 0;

        for(int i = 1 ; i < n ; i++) {
            int sell = prices[i];

            if(sell >= buy) {
                profit += sell - buy;  
            } 
            buy = sell;
        }
        return profit;
    }
};