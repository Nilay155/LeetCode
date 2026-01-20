class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // BFS for shortest path
        int n = grid.size();

        queue<tuple<int,int,int>> q;
        if(grid[0][0] == 1) return -1;
        vector<vector<bool>> vis(n,vector<bool>(n,false));

        q.push({0,0,1});
        vis[0][0] = true;

        int dx[] = {-1,1,0,0,-1,-1,1,1};
        int dy[] = {0,0,-1,1,1,-1,1,-1};

        while(!q.empty()) {
            auto [r,c,length] = q.front(); q.pop();

            if(r == n-1 && c == n-1) return length;

            for(int i = 0 ; i < 8 ; i++) {
                int nr = r + dx[i], nc = c + dy[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && 
                   grid[nr][nc] == 0 && !vis[nr][nc]) {
                    q.push({nr,nc,length + 1});
                    vis[nr][nc] = true;
                  }
            }

        }
        return -1;
    }
};