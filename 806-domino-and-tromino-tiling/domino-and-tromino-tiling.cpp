class Solution {
public:
    int MOD = 1e9 + 7;
    int numTilings(int n) {
       vector<long long int> dp(n+3);
       dp[0] = 1;
       dp[1] = 1;
       dp[2] = 2;
       dp[3] = 5;

       for(int i = 4 ; i <= n ; i++) {
            long long int domino = (dp[i-1] + dp[i-2])%MOD;
            long long int tromino = 0;
            for(int j = 3 ; j <= i ; j++) {
                tromino = ((tromino + 2*dp[i-j])%MOD);
            }
            dp[i] = (domino + tromino) % MOD;
       }  
       return dp[n];
    }
};