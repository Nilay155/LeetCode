class Solution {
public:
    int tabulation(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i = 1 ; i <= n ; i++) {
            dp[m][i] = grid[m-1][i-1];
        }

        for(int i = m-1 ; i >= 1 ; i--) {
            for(int j = 1 ; j <= n ; j++) {
                dp[i][j] = 1e9;

                for(int k = 1 ; k <= n ; k++) {
                    if(j != k) {
                        dp[i][j] = min(dp[i][j],grid[i-1][j-1] + dp[i+1][k]);
                    }
                }
            }
        }

        int mini = 1e9;
        for(int i = 1 ; i <= n ; i++) mini = min(mini,dp[1][i]);
        return mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        return tabulation(grid);
    }
};