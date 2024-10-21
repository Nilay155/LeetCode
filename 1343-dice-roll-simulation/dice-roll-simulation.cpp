class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[5001][7][16];
    int solve(vector<int> &nums,int n,int last,int cnt) {
        if(n == 0) return 1;
        if(dp[n][last][cnt] != -1) return dp[n][last][cnt];
        long long int ans = 0;

        for(int i = 1 ; i <= 6 ; i++) {
            if(last == i) {
                if(cnt < nums[last-1])
                    ans = (ans + solve(nums,n-1,i,cnt + 1)) % MOD;
            } else {
                ans = (ans + solve(nums,n-1,i,1)) % MOD;
            }
        }
        return dp[n][last][cnt] = ans%MOD;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return solve(rollMax,n,0,0);
    }
};