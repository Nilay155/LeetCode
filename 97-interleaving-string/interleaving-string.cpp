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
        memset(dp,-1,sizeof(dp));
        return ff(s1,s2,s3,0,0,0);
        // int l = s1.length(), m = s2.length(), n = s3.length();
    }   
};