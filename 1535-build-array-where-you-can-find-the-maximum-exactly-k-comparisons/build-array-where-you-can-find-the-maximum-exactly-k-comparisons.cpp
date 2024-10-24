class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[51][51][101];
    int solve(int n,int m,int k,int i,int last) {
        if(i >= n && k == 0) return 1;
        if(i >= n || k < 0) return 0;
        if(dp[i][k][last] != -1) return dp[i][k][last];

        int res = 0;
        for(int j = 1 ; j <= m ; j++) {
            if(j > last) res = (res + solve(n,m,k-1,i+1,max(j,last))) % MOD;
            else res = (res + solve(n,m,k,i+1,max(j,last))) % MOD;
        }
        return dp[i][k][last] = res;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,m,k,0,0);
    }
};