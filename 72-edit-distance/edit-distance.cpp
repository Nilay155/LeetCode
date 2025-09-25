class Solution {
private:
    int dp[501][501];
    int f(string &s,string &t,int i,int j) {
        if(i == 0) {
            return j;
        }
        if(j == 0) {
            return i;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) return dp[i][j] = f(s,t,i-1,j-1);
        else {
            // replace
            int replace = 1 + f(s,t,i-1,j-1);
            int deletee = 1 + f(s,t,i-1,j);
            int insert = 1 + f(s,t,i,j-1);

            return dp[i][j] =  min({replace,insert,deletee});
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        memset(dp,0,sizeof(dp));
        // return f(word1,word2,n,m);

        for(int j = 0 ; j <= m ; j++) {
            dp[0][j] = j;
        }
        for(int i = 0 ; i <= n ; i++) {
            dp[i][0] = i;
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {

                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({
                            dp[i-1][j-1],dp[i-1][j],dp[i][j-1]
                    });
                }
            }
        }
        return dp[n][m];
    }
};