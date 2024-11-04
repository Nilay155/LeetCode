class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        
        // Sorting robots and factories for optimal distance calculations
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Separating factory limits and distances for easier access
        vector<int> limit(m), distance(m);
        for (int i = 0; i < m; i++) {
            distance[i] = factory[i][0];
            limit[i] = factory[i][1];
        }

        // Use a large number as a placeholder for infinity within a safe range
        const long long INF = 1e15;

        // Initialize DP table
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));

        // Base case: No robots to repair means total distance is zero
        for (int j = 0; j <= m; j++) {
            dp[n][j] = 0;
        }

        // Fill the DP table in bottom-up manner
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = dp[i][j + 1]; // Option to skip this factory

                long long currentDistance = 0;
                for (int cnt = 0; cnt < limit[j] && i + cnt < n; cnt++) {
                    currentDistance += abs(distance[j] - robot[i + cnt]);
                    dp[i][j] = min(dp[i][j], currentDistance + dp[i + cnt + 1][j + 1]);
                }
            }
        }

        // The answer is the minimum distance to repair all robots starting from the first robot and first factory
        return dp[0][0];
    }
};
