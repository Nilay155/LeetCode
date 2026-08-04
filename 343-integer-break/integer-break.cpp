typedef long long ll;
class Solution {
public:
    int integerBreak(int n) {
        
        vector<ll> dp(n + 1,0);
        dp[0] = 0, dp[1] = 1;

        for(int k = 2 ; k <= n ; k++) {
            for(int f = 1 ; f < k ; f++) {
                ll z = max(dp[k - f],(ll) (k - f));
                dp[k] = max(dp[k],1LL * f * z);
            }
        }
        // for(int k = 1 ; k <= n ; k++) cout << dp[k] << " : ";
        return dp[n];
    }
};