class Solution {
private:
    int dp[301][5001];
    int f(vector<int> &coins,int i,int amount) {
        if(amount == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        
        if(coins[i-1] <= amount)   
            return dp[i][amount] = f(coins,i,amount-coins[i-1]) + f(coins,i-1,amount);
        else 
            return dp[i][amount] = f(coins,i-1,amount);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // memset(dp,-1,sizeof(dp));
        // return f(coins,n,amount);
        vector<vector<long long>> dp(n+1,vector<long long>(amount+1));

        long long mod = 1e18;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;

        for(int i = 1; i <= n ; i++) {
            for(int a = 1 ; a <= amount ; a++) {

                if(coins[i-1] <= a) 
                    dp[i][a] = (dp[i][a-coins[i-1]] + dp[i-1][a]) % mod;
                else 
                    dp[i][a] = dp[i-1][a] % mod;
            }
        }
        return dp[n][amount];
    }
};