class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int j = m-1 ; j >= 0 ; j--) {

                int right = dp[i+1][j];
                int bottom = dp[i][j+1];
                int diagonal = dp[i+1][j+1];

                int mini = min({right,bottom,diagonal});
                if(matrix[i][j]) {
                    dp[i][j] = 1 + mini;
                }
            }
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                ans += dp[i][j];
                // cout << dp[i][j] << "  ";
            }
        }
        return ans;
    }
};