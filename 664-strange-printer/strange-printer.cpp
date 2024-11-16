class Solution {
public:
    int dp[101][101];
    int solve(string &s,int l,int r) {
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];

        int left = l;
        while(l+1 <= r && s[l] == s[l+1]) {
            l += 1;
        }

        int ans = 1 + solve(s,l+1,r);

        for(int k = l+1 ; k <= r ; k++) {
            if(s[l] == s[k]) {
                ans = min(ans,solve(s,k+1,r) + solve(s,l,k-1));
            }
        }
        return dp[left][r] = ans;
    }
    int strangePrinter(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1);
    }
};