class Solution {
public:
    bool isSafe(int x,int y,int n,int m,vector<vector<int>> &dp,vector<vector<int>> &grid) {
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
            if(dp[x][y] == 0) return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dp(n,vector<int> (m,0));
        int minTime = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    dp[i][j] = 1;
                }
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!q.empty()) {
            auto ele = q.front();
            q.pop();

            int x = ele.first;
            int y = ele.second;

            for(int i = 0 ; i < 4 ; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(isSafe(newX,newY,n,m,dp,grid)) {
                    q.push({newX,newY});
                    dp[newX][newY] = 1 + dp[x][y];
                }
            }
        }

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {

                if(grid[i][j] == 1 && dp[i][j] == 0) return -1;
                minTime = max(minTime,dp[i][j]);
            }
        }
        cout << minTime << endl;
        return minTime > 0 ? minTime-1 : minTime;
    }
};