class Solution {
private:
    int dp[501][501];
    int f(string &word1,string &word2,int i,int j) {
        if(i >= word1.length()) {
            return word2.length() - j;
        }
        if(j >= word2.length()) {
            return word1.length() - i;
        }
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        if(word1[i] == word2[j]) {
            ans = min(ans,f(word1,word2,i + 1,j + 1));
        } else {
            // word1[i] != word2[j]
            int op1 = 1 + f(word1,word2,i,j + 1); // insertion
            int op2 = 1 + f(word1,word2,i + 1,j + 1); // replace
            int op3 = 1 + f(word1,word2,i + 1,j); // deletion
            ans = min(ans,min({op1,op2,op3}));
        }
        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp,1e9,sizeof(dp));
        // return f(word1,word2,0,0);
        int n = word1.length(), m = word2.length();
        for(int i = 0 ; i <= n ; i++) 
            dp[i][0] = i; 
        for(int j = 0 ; j <= m ; j++)
            dp[0][j] = j;
        
        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                dp[i][j] = 1e9;
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i][j],1 + dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j],1  + dp[i - 1][j - 1]);
                    dp[i][j] = min(dp[i][j],1 + dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};