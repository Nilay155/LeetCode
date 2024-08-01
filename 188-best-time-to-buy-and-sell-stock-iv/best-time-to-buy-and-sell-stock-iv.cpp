class Solution {
public:
    int func(vector<int> &prices,int i,int k,bool flag,int n,vector<vector<vector<int>>> &dp) {
        if(k == 0) return 0;
        if(i >= n) return 0;

        if(dp[i][flag][k] != -1) return dp[i][flag][k];

        int buy = 0;
        int sell = 0;

        if(flag) {
            buy = max(-prices[i] + func(prices,i+1,k,!flag,n,dp),
                      0 + func(prices,i+1,k,flag,n,dp));
        } else {
            sell = max(prices[i] + func(prices,i+1,k-1,!flag,n,dp),
                       0 + func(prices,i+1,k,flag,n,dp));
        }

        return dp[i][flag][k] = max(buy,sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        bool flag = true;
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(k+1,-1)));
        return func(prices,i,k,flag,n,dp);
    }
};