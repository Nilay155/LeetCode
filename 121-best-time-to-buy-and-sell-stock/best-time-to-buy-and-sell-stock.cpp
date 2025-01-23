class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int ans = 0;
        for(int i = 1 ; i < n ;i++) {
            int currPrice = prices[i];
            ans = max(ans,currPrice-minPrice);
            minPrice = min(minPrice,currPrice);
        }
        return ans;
    }
};