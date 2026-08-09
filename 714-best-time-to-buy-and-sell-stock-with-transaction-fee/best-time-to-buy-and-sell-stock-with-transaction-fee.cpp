class Solution {
public:
    int dp[50001][2];
    int f(vector<int> &prices,int &fee,int i,bool flag,int &n) {
        if(i >= n)
            return 0;
        if(dp[i][flag] != -1)
            return dp[i][flag];

        int ans = 0;
        if(flag) {
            // buy option is open
            ans = max(ans,-prices[i] + f(prices,fee,i + 1,false,n));
            ans = max(ans,f(prices,fee,i + 1,true,n));
        } else {
            // sell option is open
            ans = max(ans,prices[i] - fee + f(prices,fee,i + 1,true,n));
            ans = max(ans,f(prices,fee,i + 1,false,n));
        }
        return dp[i][flag] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // memset(dp,-1,sizeof(dp));
        // return f(prices,fee,0,true,m);
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][1] = -prices[0];

        for(int i = 1 ; i < n ; i++) {
            dp[i][1] = max(-prices[i] + dp[i - 1][0],dp[i - 1][1]);
            dp[i][0] = max(prices[i] - fee + dp[i - 1][1],dp[i - 1][0]);
        }

        return dp[n - 1][0];
    }
};