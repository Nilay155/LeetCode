class Solution {
private:
    void f(vector<vector<int>> &grid,vector<vector<int>> &dist,int i,int j,vector<vector<bool>> &vis) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int,int>> q,nq;
        q.push({i,j});
        vis[i][j] = true;
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            dist[x][y] = 0;
            nq.push({x,y});
            for(int k = 0 ; k < 4 ; k++) {
                int nx = dx[k] + x, ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == 1) {
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
        vector<vector<bool>> newVis(n,vector<bool>(m,false));
        int round = 1;
        while(!nq.empty()) {
            int sz = nq.size();
            while(sz--) {
                auto [x,y] = nq.front(); nq.pop();
                for(int k = 0 ; k < 4 ; k++) {
                    int nx = dx[k] + x, ny = y + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && !newVis[nx][ny]) {
                        dist[nx][ny] = round;
                        nq.push({nx,ny});
                        newVis[nx][ny] = true;
                    } 
                }
            }
            round += 1;
        }
        return ;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dist1(n,vector<int>(m,1e9));
        vector<vector<int>> dist2(n,vector<int>(m,1e9));
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    if(count == 0)
                        f(grid,dist1,i,j,vis);
                    else
                        f(grid,dist2,i,j,vis);
                    count += 1;
                }
            }
        }
        if(count < 2) 
            return 0;
        
        int ans = n * m;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(dist1[i][j] == 0 || dist2[i][j] == 0 || dist1[i][j] == 1e9 || dist2[i][j] == 1e9) 
                    continue;
                else 
                    ans = min(ans,dist1[i][j] + dist2[i][j] - 1);

            }
        }
        return ans;
    }
};