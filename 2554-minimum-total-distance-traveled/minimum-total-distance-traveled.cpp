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

        // Initialize DP table
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(101, LLONG_MAX)));
        
        // Base case: No robots to repair means total distance is zero
        for (int j = 0; j <= m; j++) {
            for (int cnt = 0; cnt <= 100; cnt++) {
                dp[n][j][cnt] = 0;
            }
        }

        // Fill the DP table in bottom-up manner
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int cnt = 0; cnt <= limit[j]; cnt++) {
                    long long op1 = LLONG_MAX;
                    long long op2 = dp[i][j + 1][0]; // Option to skip this factory

                    // If the current factory can still repair more robots
                    if (cnt < limit[j]) {
                        long long mini = abs(distance[j] - robot[i]);
                        long long rec = dp[i + 1][j][cnt + 1];
                        if (rec != LLONG_MAX) {
                            op1 = mini + rec;
                        }
                    }

                    dp[i][j][cnt] = min(op1, op2);
                }
            }
        }

        // The answer is the minimum distance to repair all robots starting from the first robot and first factory
        return dp[0][0][0];
    }
};
