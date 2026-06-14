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
        memset(dp,-1,sizeof(dp));
        return f(word1,word2,0,0);
    }
};