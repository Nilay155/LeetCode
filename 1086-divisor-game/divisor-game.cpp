class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1);
        dp[1] = false;

        for(int i = 2 ; i <= n ; i++) {
            for(int j = i-1 ; j > 0 ; j--) {
                
                if(i%j == 0) {
                    int val = i-j;
                    dp[i] = dp[i] | !dp[val];
                }
            }
        }
        return dp[n];
    }
};