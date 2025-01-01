class Solution {
public:
    int MOD = 1e9+7;
    int dp[100001];
    int solve(int low,int high,int zero,int one,int len) {
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];

        int ans = 0;
        if(len >= low && len <= high) ans++;

        ans = (ans + (solve(low,high,zero,one,len+zero) + solve(low,high,zero,one,len+one))%MOD)%MOD;
        return dp[len] = ans; 
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return solve(low,high,zero,one,0);
    }
};