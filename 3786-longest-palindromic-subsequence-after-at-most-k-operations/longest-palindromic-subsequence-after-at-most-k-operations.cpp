class Solution {
private:
    int dp[201][201][201];
    int f(string &str,int l,int r,int k) {
        if(l == r)
            return 1;
        if(l > r)
            return 0;
        if(dp[l][r][k] != -1)
            return dp[l][r][k];

        int op1 = max(f(str,l + 1,r,k),f(str,l,r - 1,k));
        
        int k1 = min(str[l] - 'a',str[r] - 'a'), 
            k2 = max(str[l] - 'a',str[r] - 'a');

        int t1 = k2 - k1, t2 = (26 - k2 + k1);
        
        int op2 = (t1 <= k) ? 2 + f(str,l + 1,r - 1,k - t1) : 0;
        int op3 = (t2 <= k) ? 2 + f(str,l + 1,r - 1,k - t2) : 0;

        return dp[l][r][k] = max({op1,op2,op3});
    }
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return f(s,0,n - 1,k);
    }
};