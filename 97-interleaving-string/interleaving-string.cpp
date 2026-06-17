class Solution {
private:
    int dp[101][101][201];
    bool ff(string &s,string &t,string &f,int i,int j,int k) {

        if(k >= f.length() && i >= s.length() && j >= t.length())
            return true;
        if(k >= f.length())
            return false;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        if((i < s.length() && s[i] == f[k]) && 
           (j < t.length() && t[j] == f[k])) {
            return dp[i][j][k] = ff(s,t,f,i + 1,j,k + 1) || ff(s,t,f,i,j + 1,k + 1);
        } else if(i < s.length() && s[i] == f[k]) {
            return dp[i][j][k] = ff(s,t,f,i + 1,j,k + 1);
        } else if(j < t.length() && t[j] == f[k]) {
            return dp[i][j][k] = ff(s,t,f,i,j + 1,k + 1);
        }
        return dp[i][j][k] = false;
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // memset(dp,-1,sizeof(dp));
        // return ff(s1,s2,s3,0,0,0);
        int n = s1.length(), m = s2.length();
        if(n + m != s3.length())
            return false;
        
        bool dp[101][101];
        memset(dp,false,sizeof(dp));
        dp[0][0] = true;
        for(int i = 1 ; i <= n ; i++) {
            if(s1[i - 1] == s3[i - 1])
                dp[i][0] = dp[i - 1][0];
        }
        for(int j = 1 ; j <= m ; j++) {
            if(s2[j - 1] == s3[j - 1]) 
                dp[0][j] = dp[0][j - 1];
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                
                if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1]; 
                } else if(s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else if(s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }   
};