class Solution {
public:
    bool solve(int n,int turn,vector<vector<int>> &dp) {
        if(n == 0) {
            return (turn == 0) ? true : false;
        }
        if(dp[n][turn] != -1) return dp[n][turn];

        bool ans = true;

        if(turn) {
            ans = false;
            for(int j = 1 ; j <= sqrt(n); j++) {
                if(j*j <= n) {
                    bool rec = solve(n-j*j,(turn == 1) ? 0 : 1,dp);
                    ans |= rec;
                }
            }
        } else {
            ans = true;
            for(int j = 1 ; j <= sqrt(n); j++) {
                if(j*j <= n) {
                    bool rec = solve(n-j*j,(turn == 1) ? 0 : 1,dp);
                    ans &= rec;
                }
            }
        }
        return dp[n][turn] = ans;
    }
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(n,1,dp);
    }
};