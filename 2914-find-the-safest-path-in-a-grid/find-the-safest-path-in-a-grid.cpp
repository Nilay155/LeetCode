class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> safeNess(n,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 0) continue;
                q.push({i,j});
                safeNess[i][j] = 0;
                vis[i][j] = true;
            }
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                    safeNess[nx][ny] =  1 + safeNess[x][y];
                }
            }
        }   
        
        vis = vector<vector<bool>> (n,vector<bool>(n,false));
        priority_queue<tuple<int,int,int>> pq;
        pq.push({safeNess[0][0],0,0});
        int ans = INT_MAX;

        while(!pq.empty()) {
            auto [cost,x,y] = pq.top(); pq.pop();
            ans = min(ans,cost);
            if(x == n-1 && y == n-1) return ans;

            for(int i = 0 ; i < 4 ; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({safeNess[nx][ny],nx,ny});
                }
            }
        }
        return ans;
    }
};