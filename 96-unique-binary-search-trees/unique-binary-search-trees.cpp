class Solution {
private:
    int dp[20][20];
    int f(int l,int r) {
        if(l >= r) 
            return 1;
        if(dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;
        for(int x = l ; x <= r ; x++) {
            int left = f(l,x - 1);
            int right = f(x + 1,r);
            ans += (left * right);
        }
        return dp[l][r] = ans;
    }
public:
    int numTrees(int n) {
        // memset(dp,-1,sizeof(dp));
        // return f(1,n);

        vector<vector<int>> dp(n + 1,vector<int>(n + 1,1));

        for(int len = 2 ; len <= n ; len++) {
            for(int k = 1 ; k + len - 1 <= n ; k++) {
                int ans = 0;
                int l = k, r = k + len - 1;
                for(int x = l ; x <= r ; x++) {
                    int left = (x - 1 >= 1 ? dp[l][x - 1] : 1);
                    int right = (x + 1 <= n ? dp[x + 1][r] : 1);
                    ans += (left * right);
                }
                dp[l][r] = ans;
            }
        }
        return dp[1][n];
    }
};