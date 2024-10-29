class Solution {
public:
    int dp[1001][1001][4];
    int solve(vector<vector<int>> &grid,int i,int j,int move,int &n,int &m) {
        if(i >= n || i < 0 || j >= m || j < 0) return 0;
        if(dp[i][j][move] != -1) return dp[i][j][move];

        int op1 = 0;
        int op2 = 0;
        int op3 = 0;
        
        if(move == 0) {
            op1 = 0 + solve(grid,i-1,j+1,1,n,m);
            op2 = 0 + solve(grid,i,j+1,2,n,m);
            op3 = 0 + solve(grid,i+1,j+1,3,n,m);
        } else {
            int x = -1;
            int y = -1;
            if(move == 1) {
                x = i+1;
                y = j-1;
            } else if(move == 2) {
                x = i;
                y = j-1;
            } else {
                x = i-1;
                y = j-1;
            }

            if(grid[x][y] < grid[i][j]) {
                // cout << grid[x][y] << " : " << grid[i][j] << endl;
                op1 = 1 + solve(grid,i-1,j+1,1,n,m);
                op2 = 1 + solve(grid,i,j+1,2,n,m);
                op3 = 1 + solve(grid,i+1,j+1,3,n,m);
            }
        }
        return dp[i][j][move] = max({op1,op2,op3});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            ans = max(ans,solve(grid,i,0,0,n,m));
        }
        return ans;
    }
};