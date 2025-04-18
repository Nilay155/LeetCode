class Solution {
public:
    int dfs(vector<int> &prices,int i,int capacity,bool flag,int n,vector<vector<vector<int>>> &dp) {
        if(capacity == 0) return 0;
        if(i >= n) return 0;
        
        if(dp[i][flag][capacity] != -1) return dp[i][flag][capacity];

        int buy = 0;
        int sell = 0;

        if(flag) {
            // We have to mandatorily buy to sell and make profits
            int option1 = -prices[i] + dfs(prices,i+1,capacity,!flag,n,dp);
            int option2 = 0 + dfs(prices,i+1,capacity,flag,n,dp);

            buy = max(option1,option2);
        } else {

            int option1 = prices[i] + dfs(prices,i+1,capacity-1,!flag,n,dp);
            int option2 = 0 + dfs(prices,i+1,capacity,flag,n,dp);

            sell = max(option1,option2);
        }
        return dp[i][flag][capacity] = max(buy,sell);
    }
    int tabulation(vector<int> &prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));

        for(int i = n-1 ; i >= 0 ;i--) {
            for(int flag = 1 ; flag >= 0 ; flag--) {
                for(int capacity =  1 ; capacity < 3 ; capacity++) {
                    int buy = 0;
                    int sell = 0;
                    if(flag) {
                        buy = max(-prices[i] + dp[i+1][flag == 0 ? 1 : 0][capacity],0 + dp[i+1][flag][capacity]);
                    } else {
                        sell = max(prices[i] + dp[i+1][flag == 0 ? 1 : 0][capacity-1],0 + dp[i+1][flag][capacity]);
                    }
                    dp[i][flag][capacity] = max(buy,sell);
                }
            }
        }

        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,0)));
        dp[0][0][1] = -prices[0];
        dp[0][0][2] = -prices[0];

        for(int i = 1 ; i < n ; i++) {
            dp[i][0][1] = max(dp[i-1][0][1],-prices[i] + dp[i-1][1][0]);
            dp[i][0][2] = max(dp[i-1][0][2],-prices[i] + dp[i-1][1][1]);

            dp[i][1][1] = max(dp[i-1][1][1],prices[i] + dp[i-1][0][1]);
            dp[i][1][2] = max(dp[i-1][1][2],prices[i] + dp[i-1][0][2]);
        }
        return dp[n-1][1][2];
    }
};