class Solution {
public:
    int dp[201][201];
    int solve(int left,int right) {
        if(left >= right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        
        int ans = 1e9;
        for(int k = left ; k <= right ; k++) {
            ans = min(ans,k + max(solve(left,k-1),solve(k+1,right)));
        }
        return dp[left][right] = ans;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};