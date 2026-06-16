class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1,0);
        dp[0] = 1;

        for(int l = 1 ; l <= n ; l++) {

            if(s[l - 1] >= '1' && s[l - 1] <= '9') {
                // 1-len decode/break
                dp[l] += dp[l - 1];
            }
            if(l >= 2 && s[l - 2] >= '1' && s[l - 2] <= '9' &&
                         s[l - 1] >= '0' && s[l - 1] <= '9' && 
                         10 * (s[l - 2]-'0') + (s[l - 1] - '0') <= 26) {

                            dp[l] += dp[l - 2];
                         }
        }
        return dp[n];
    }
};