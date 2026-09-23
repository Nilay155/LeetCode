class Solution {
private:
    // int dp[501][501];
    int f(string s,int l,int r,vector<vector<int>> &dp) {
        if(l >= r)
            return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        if(s[l] == s[r])
            return dp[l][r] = f(s,l + 1, r - 1,dp);
        else
            return dp[l][r] = min(1 + f(s,l + 1,r,dp),1 + f(s,l,r - 1,dp));
    } 
public:
    int minInsertions(string s) {
        int n = s.length();
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(int l = 0 ; l < n ; l++)
            for(int r = 0 ; r < n ; r++)
                if(l >= r)
                    dp[l][r] = 0;
                
        for(int l = n - 2 ; l >= 0 ; l--) {
            for(int r = 1 ; r < n ; r++) {
                if(l >= r)
                    continue;
                    
                if(s[l] == s[r])
                    dp[l][r] = dp[l + 1][r - 1];
                else
                    dp[l][r] = 1 + min(dp[l + 1][r],dp[l][r - 1]);
            }
        }
        return dp[0][n - 1];
    }
};