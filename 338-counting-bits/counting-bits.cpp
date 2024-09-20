class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        if(n == 0) return {0};
        if(n == 1) return {0,1};
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3 ; i <= n ; i++) {
            if(i&1) {
                dp[i] = dp[i/2] + 1;
            } else {
                dp[i] = dp[i/2];
            }
        }
        return dp;
    }
};