class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int a = costs[0], b = costs[1], c = costs[2];

        vector<int> dp(n,INT_MAX);
        dp[n - 1] = min({a,b,c});

        for(int i = n - 2 ; i >= 0 ; i--) {
            
            // 1 day pass
            dp[i] = min(dp[i], a + dp[i + 1]);
            
            int day = days[i], j = 0;
            // 7 day pass
            for(j = i ; j < n && days[j] < (day + 7) ; j++);

            if(j == n)
                dp[i] = min(dp[i],b);
            else if(j == i)
                dp[i] = min(dp[i],b + dp[i + 1]);
            else
                dp[i] = min(dp[i],b + dp[j]);

            // 30 day pass
            for(j = i ; j < n && days[j] < (day + 30) ; j++);
            
            if(j == n)
                dp[i] = min(dp[i],c);
            else if(j == i)
                dp[i] = min(dp[i],c + dp[i + 1]);
            else
                dp[i] = min(dp[i],c + dp[j]);
        }
        return dp[0];
    }
};