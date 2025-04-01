class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        
        vector<long long> dp(n,0);
        dp[n-1] = questions[n-1][0];

        for(int i = n-2 ; i >= 0 ; i--) {
            int shift = questions[i][1];
            int points = questions[i][0];

            long long temp = points;
            if(i+shift+1 < n) temp += dp[i+shift+1];
            temp = max(dp[i+1],temp);
            dp[i] = temp;
        }
        return dp[0];
    }
};