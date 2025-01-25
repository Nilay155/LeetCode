class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;

        for(int i = 2 ; i <= n ; i++) {
            for(int j = i-1 ; j >= 1 ; j--) {
                dp[i] = max(dp[i],j * max(i-j,dp[i-j]));
            }
        }

        return dp[n];
    }
};