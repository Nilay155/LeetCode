class Solution {
private:
    int dp[2001][2001];
    int f(string &s,string &p,int i,int j) {
        // Base-Cases
        if(i == 0 && j == 0) return true;
        if(i == 0 && j != 0) {
            while(j > 0) {
                if(p[j-1] != '*') return false;
                j--;
            }
            return true;
        }
        if(i == 0 || j == 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p[j-1]) return dp[i][j] = f(s,p,i-1,j-1);
        else if(p[j-1] == '?') return dp[i][j] = f(s,p,i-1,j-1);
        else if(p[j-1] == '*') return dp[i][j] = f(s,p,i-1,j) || f(s,p,i,j-1);
        else return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        // memset(dp,-1,sizeof(dp));
        int n = s.length(), m = p.length();
        // return f(s,p,n,m);

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int j = 0 ; j <= m ; j++)
            dp[0][j] = true;

        for(int j = 1 ; j <= m ; j++) {
            if(p[j-1] == '*') dp[0][j] = dp[0][j] & dp[0][j-1];
            else dp[0][j] = false;
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] | dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};