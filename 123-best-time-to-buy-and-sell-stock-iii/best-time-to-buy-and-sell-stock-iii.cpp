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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0, capacity = 2;
        bool flag = true;
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return dfs(prices,i,capacity,flag,n,dp);
    }
};