using ti = tuple<int,int,int>;
class Solution {
private:
    int f(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &vis) {

        if(i == grid.size() - 1 && j == grid[0].size() - 1)
            return 0;
        
        if(i >= grid.size() || j >= grid[0].size())
            return 1e9;
        
        vis[i][j] = true;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int dz[] = {4,3,2,1};
        int c = grid[i][j], ans = 1e9;
        
        for(int k = 0 ; k < 4 ; k++) {
            int ni = dx[k] + i, nj = dy[k] + j;
            
            if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !vis[ni][nj]) {

                int rec = 0;
                if(c != dz[k]) {
                    rec += 1;
                }
                rec = rec + f(grid,ni,nj,vis);
                ans = min(ans,rec);
            }
        }
        vis[i][j] = false;
        return ans;
    }
    int bfs(vector<vector<int>> &grid,int &n,int &m) {
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> cost(n,vector<int>(m,1e9));

        priority_queue<ti,vector<ti>,greater<ti>> pq;
        pq.push({0,0,0});
        cost[0][0] = 0;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int dz[] = {4,3,2,1};

        while(!pq.empty()) {
            auto [k,x,y] = pq.top(); pq.pop();
            vis[x][y] = true;

            if(x == n - 1 && y == m - 1)
                return k;

            for(int u = 0 ; u < 4 ; u++) {
                int nx = dx[u] + x, ny = dy[u] + y;
                int move = (grid[x][y] == dz[u]) ? 0 : 1;

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    if(cost[x][y] + move < cost[nx][ny]) {
                        cost[nx][ny] = cost[x][y] + move;
                        pq.push({cost[nx][ny],nx,ny});
                    }
                }
            }
        }
        return -1;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // vector<vector<bool>> vis(n,vector<bool>(m,false));
        // return f(grid,0,0,vis);
        return bfs(grid,n,m);
    }
};