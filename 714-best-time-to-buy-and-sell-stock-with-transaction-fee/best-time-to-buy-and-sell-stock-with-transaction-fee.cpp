class Solution {
public:
    int dfs(vector<int> &prices,int i,int flag,int fee,int n,vector<vector<int>> &dp) {
        if(i >= n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];

        int buy = 0;
        int sell = 0;

        if(flag == 0) {
            buy = max(-prices[i] + dfs(prices,i+1,1,fee,n,dp),0 + dfs(prices,i+1,flag,fee,n,dp));
        } else {
            sell = max(prices[i]-fee + dfs(prices,i+1,0,fee,n,dp),0 + dfs(prices,i+1,flag,fee,n,dp));
        } 
        return dp[i][flag] = max(buy,sell);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int i = 0;
        int flag = 0;

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return dfs(prices,i,flag,fee,n,dp);
    }
};