class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<vector<int>> cache;
    int solve(int n,int i) {
        if(n == 0) return 1;
        if(cache[n][i] != -1) return cache[n][i];

        int ans = 0;
        for(int j = 1 ; j < 11 ; j++) {

            if(i-1 == -1 || dp[i-1][j-1]) {
                ans = (ans + solve(n-1,j)) % MOD;
            }
        }
        return cache[n][i] = ans%MOD;
    }
    int func(int n) {
        vector<int> curr(10,1); // n = 1

        for(int i = 2 ; i <= n ; i++) {
            vector<int> next(10,0);
            for(int j = 0 ; j < 10 ; j++) {
                int temp = 0;
                for(int k = 0 ; k < 10 ; k++) {
                    if(dp[j][k]) {
                        temp = (temp + curr[k])%MOD;
                    }
                }
                next[j] = temp%MOD;
            }
            curr = next;
        }
        int ans = 0;
        for(int i = 0 ; i < 10 ; i++) {
            ans = (ans + curr[i]) % MOD;
        }
        return ans;
    }
    int knightDialer(int n) {
        dp = vector<vector<int>>(10,vector<int>(10,0));
        cache = vector<vector<int>>(n+1,vector<int>(11,-1));
        dp[0][4] = dp[0][6] = 1;
        dp[1][6] = dp[1][8] = 1;
        dp[2][9] = dp[2][7] = 1;
        dp[3][4] = dp[3][8] = 1;
        dp[4][3] = dp[4][9] = dp[4][0] = 1;
        dp[6][0] = dp[6][1] = dp[6][7] = 1;
        dp[7][2] = dp[7][6] = 1;
        dp[8][1] = dp[8][3] = 1;
        dp[9][2] = dp[9][4] = 1;
        // return solve(n,0);
        return func(n);
    }
};