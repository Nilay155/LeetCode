class Solution {
private:
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {

                if(land[i][j] == 1 && !vis[i][j]) {

                    int sx = i, sy = j;
                    int ex = i, ey = j;

                    queue<pair<int,int>> q;
                    q.push({sx,sy});
                    vis[sx][sy] = true;

                    int dx[] = {0,0,1,-1};
                    int dy[] = {-1,1,0,0};
                    while(!q.empty()) {
                        auto [x,y] = q.front(); q.pop();

                        for(int k = 0 ; k < 4 ; k++) {
                            int nx = x + dx[k], ny = y + dy[k];
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && land[nx][ny] == 1) {

                                ex = max(ex,nx), ey = max(ey,ny);
                                vis[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                    ans.push_back({sx,sy,ex,ey});
                }
            }
        }
        return ans;
    }
};