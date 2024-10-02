class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int m,int n,int moves,int startRow,int startCol) {
        if(moves < 0) return 0;
        if(m<startRow || n<startCol || startRow<=0 || startCol<=0)               
            return 1;
    

        // Down
        int op1 = solve(m,n,moves-1,startRow+1,startCol) % MOD;
        // Up
        int op2 = solve(m,n,moves-1,startRow-1,startCol) % MOD;
        // Left
        int op3 = solve(m,n,moves-1,startRow,startCol-1) % MOD;
        //Right
        int op4 = solve(m,n,moves-1,startRow,startCol+1) % MOD;

        long long int res = ((op1 + op2)%MOD + (op3 + op4)%MOD)%MOD;
        return res;
    }
    int tabulation(int m,int n,int moves,int startRow,int startCol) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[startRow][startCol] = 1;
        int count = 0;
        for(int move = 1 ; move <= moves ; move++) {
            vector<vector<int>> next(m,vector<int>(n,0));
            for(int i = 0 ; i < m ; i++) {
                for(int j = 0 ; j < n ; j++) {

                    if(j == n-1) count =(count + dp[i][j])%MOD;
                    if(i == m-1) count =(count + dp[i][j])%MOD;
                    if(i == 0) count =(count + dp[i][j])%MOD;
                    if(j == 0) count =(count + dp[i][j])%MOD;

                   next[i][j] = (
                        ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % MOD +
                        ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % MOD
                    ) % MOD;
                } 
            }
            dp = next;
        }
        return count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return tabulation(m,n,maxMove,startRow,startColumn);
    }
};