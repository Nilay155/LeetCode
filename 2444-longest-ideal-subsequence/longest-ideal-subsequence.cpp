class Solution {
private:
    int dp[100001][27];
    int f(string &s,int i,int p,int &k,int &n) {

        if(i >= n)
            return 0;
        if(dp[i][p] != -1)
            return dp[i][p];

        int ans = f(s,i + 1,p,k,n);
        
        int c = (s[i] - 'a') + 1;
        if(p == 0 || abs(c - p) <= k) {
            ans = max(ans,1 + f(s,i + 1,c,k,n));
        }
        return dp[i][p] = ans;
    }
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return f(s,0,0,k,n);
    }
};