class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1,0);

        for(int i = 0 ; i <= n ; i++) {
            int cnt = 0;
            for(int b = 0 ; b < 32 ; b++) {
                if(i & (1 << b)) 
                    cnt += 1;
            }
            dp[i] = cnt;
        }
        return dp;
    }
};