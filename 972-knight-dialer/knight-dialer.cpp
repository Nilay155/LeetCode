class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int knightDialer(int n) {
        vector<vector<int>> dp(4,vector<int>(3,1));
        dp[3][0] = dp[3][2] = 0;

        vector<vector<int>> moves = {{-2,-1},{-1,-2},{-2,1},{2,-1},{1,-2},{2,1},{1,2},{-1,2}};
        
        for(int i = 2 ; i <= n ; i++) {
            vector<vector<int>> next(4,vector<int>(3,0));
            for(int u = 0 ; u < 3 ; u++) {
                for(int v = 0 ; v < 3 ; v++) {
                    for(int k = 0 ; k < 8 ; k++) {
                        int nu = moves[k][0] + u;
                        int nv = moves[k][1] + v;
                        if(nu >= 0 && nu <= 3 && nv >= 0 && nv <= 2) {
                            next[u][v] = (next[u][v] + dp[nu][nv]) % MOD;
                        }
                    }
                }
            }
            for(int k = 0 ; k < 8 ; k++) {
                int nu = moves[k][0] + 3;
                int nv = moves[k][1] + 1;
                if(nu >= 0 && nu <= 3 && nv >= 0 && nv <= 2) {
                    next[3][1] = (next[3][1] + dp[nu][nv]) % MOD;
                }
            }
            dp = next;
        }
        int ans = 0;
        for(int i = 0 ; i < 3 ; i++) {
            for(int j = 0 ; j < 3 ; j++) {
                ans = (ans + dp[i][j]) % MOD;
            }
        }   
        ans = (ans + dp[3][1]) % MOD;
        return ans;
    }
};