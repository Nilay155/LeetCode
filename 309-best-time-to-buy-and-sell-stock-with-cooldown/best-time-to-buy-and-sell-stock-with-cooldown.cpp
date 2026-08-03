class Solution {
private:
    int dp[5003][2];
    int f(vector<int> &prices,int i,bool buy,int &n) {
        if(i >= n)
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int ans = 0;
        if(buy) {
            int rec1 = -prices[i] + f(prices,i + 1,false,n);
            int rec2 = f(prices,i + 1,true,n);
            ans = max(ans,max(rec1,rec2));
        } else {
            int rec1 = prices[i] + f(prices,i + 2,true,n);
            int rec2 = f(prices,i + 1,false,n);
            ans = max(ans,max(rec1,rec2));
        }
        return dp[i][buy] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        
        dp[0][1] = -prices[0];
        for(int i = 1 ; i < n ; i++) {

            // Buy,not-necessary to buy
            int buy1 = -prices[i] + (i - 2 >= 0 ? dp[i - 2][0] : 0);
            int buy2 = dp[i - 1][1];

            // Sell,not-necessary to sell
            int sell1 = prices[i] + dp[i - 1][1];
            int sell2 = dp[i - 1][0];

            dp[i][1] = max(buy1,buy2);
            dp[i][0] = max(sell1,sell2);
        }
        return dp[n - 1][0];
    }
};