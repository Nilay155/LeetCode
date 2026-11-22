class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> distances(n,vector<int>(n,INT_MAX));
        queue<tuple<int,int,int>> q;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j])
                    q.push({i,j,0}), distances[i][j] = 0;
            }
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        int maxi = 0;

        while(!q.empty()) {
            auto [x,y,distance] = q.front(); q.pop();
            maxi = max(maxi,distance);
            for(int k = 0 ; k <= 3 ; k++) {
                int nx = x + dx[k], ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && 
                   distances[nx][ny] > 1 + distances[x][y]) {
                    distances[nx][ny] = 1 + distances[x][y];
                    q.push({nx,ny,distances[nx][ny]});
                   }
            }
        }
        return maxi == 0 ? -1 : maxi;
    }
};