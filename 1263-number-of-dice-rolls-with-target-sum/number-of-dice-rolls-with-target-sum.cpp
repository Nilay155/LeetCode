#define ll long long int
class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int n,int k,int target) {
        if(target == 0) return 1;
        if(n == 0) return 0;

        ll res = 0;

        for(int i = 1 ; i <= k ; i++) {
            if(i <= target) res = (res + solve(n-1,k,target-i))%MOD;
        }
        return res%MOD;
    }
    int tabulation(int n,int k,int target) {
        vector<vector<ll>> dp(n+1,vector<ll>(target+1,0));
        dp[0][0] = 1;

        for(int i = 1 ; i <= n ; i++) {
            for(int t = i ; t <= target ; t++) {
                ll temp = 0;
                for(int j = 1 ; j <= k ; j++) {;
                    if(t-j >= 0) temp = (temp + dp[i-1][t-j])%MOD;
                }
                dp[i][t] = temp%MOD;
            }
        }
        // for(int i = 0 ;i <= n ; i++) {
        //     for(int j = 0 ; j <= target ; j++) cout << dp[i][j] << "  ";
        //     cout << endl;
        // }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        return tabulation(n,k,target);
    }
};