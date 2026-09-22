using ti = tuple<int,int,int>;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> cost(n,vector<int>(m,1e9));
        cost[0][0] = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[0][0] = true;
        
        bool flag = false;
        priority_queue<ti,vector<ti>,greater<ti>> pq;
        if(grid[0][1] <= 1)
            pq.push({1,0,1}), cost[0][1] = 1, flag = true;
        if(grid[1][0] <= 1)
            pq.push({1,1,0}), cost[1][0] = 1, flag = true;
        if(flag)
            pq.push({0,0,0});
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while(!pq.empty()) {

            auto [k,x,y] = pq.top(); pq.pop();
            if(x == n - 1 && y == m - 1)
                return k;
            vis[x][y] = true;
            
            for(int i = 0 ; i < 4 ; i++) {
                int nx = dx[i] + x, ny = y + dy[i];
                int ops = 0;

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    
                    if(grid[nx][ny] > k) {
                        int diff = grid[nx][ny] - k;
                        ops = (diff & 1) ? diff : diff + 1;
                    } else {
                        ops = 1;
                    }

                    if(cost[nx][ny] == 1e9 || ops + k < cost[nx][ny]) {
                        cost[nx][ny] = ops + k;
                        pq.push({cost[nx][ny],nx,ny});
                    }

                }
            }
        }
        return -1;

    }
};