class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int i = n ; i >= 0 ; i--) {
            dp[i][m] = n-i;
        }
        for(int i = m ; i >= 0 ; i--) {
            dp[n][i] = m-i;
        }
        for(int i = n-1 ; i >= 0 ; i--) {

            for(int j = m-1 ; j >= 0 ; j--) {

                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                }
            }
        }

        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= m ; j++) {
                cout << dp[i][j] << "  ";
            }cout << endl;
        }
        return dp[0][0];
    }
};