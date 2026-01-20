class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high+1,0);
        dp[0] = 1;

        for(int len = 1 ; len <= high ; len++) {

            if(len - zero >= 0) dp[len] = (dp[len] + dp[len - zero]) % MOD;
            if(len - one >= 0) dp[len] = (dp[len] + dp[len - one]) % MOD;
        }
        int ans = 0;

        for(int k = low ; k <= high ; k++) {
            ans = (ans + dp[k]) % MOD;
        }
        return ans;
    }
};