class Solution {
public:
    int solve(vector<vector<int>> &matrix,int i,int j,int &n,int &m,int move,
                vector<vector<vector<int>>> &dp) {

                        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
                        if(dp[i][j][move] != -1) return dp[i][j][move];

                        int right = 0;
                        int left = 0;
                        int top = 0;
                        int bottom = 0;

                        if(move == 4) {
                            //Starting Point
                            right = 1 + solve(matrix,i,j+1,n,m,0,dp);
                            left = 1 + solve(matrix,i,j-1,n,m,1,dp);
                            top = 1 + solve(matrix,i-1,j,n,m,2,dp);
                            bottom = 1 + solve(matrix,i+1,j,n,m,3,dp);
                        } else {
                            int x = -1;
                            int y = -1;

                            if(move == 0) {
                                x = i;
                                y = j-1;
                            } else if(move == 1) {
                                x = i;
                                y = j+1;
                            } else if(move == 2) {
                                x = i+1,
                                y = j;
                            } else {
                                x = i-1;
                                y = j;
                            }
                            if(x < 0 || y < 0 || x >= n || y >= m);
                            else if(matrix[i][j] > matrix[x][y]) {
                                right = 1 + solve(matrix,i,j+1,n,m,0,dp);
                                left = 1 + solve(matrix,i,j-1,n,m,1,dp);
                                top = 1 + solve(matrix,i-1,j,n,m,2,dp);
                                bottom = 1 + solve(matrix,i+1,j,n,m,3,dp);
                            }
                        }

                        return dp[i][j][move] = max({right,left,top,bottom});
                }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = INT_MIN;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(5,-1)));
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                for(int move = 0 ; move <= 4 ; move++) {
                    if(dp[i][j][move] == -1)
                        ans = max(ans,solve(matrix,i,j,n,m,4,dp));
                }
            }
        }
        return ans;
    }
};