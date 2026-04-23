class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;

        pq.push({grid[0][0],0,0});
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vis[0][0] = true;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};

        while(!pq.empty()) {
            auto [time,i,j] = pq.top(); pq.pop();
            if(i == n - 1 && j == n - 1)
                return time;
            
            for(int k = 0 ; k < 4 ; k++) {
                int ni = i + dx[k], nj = j + dy[k];

                if(ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj]) {
                    vis[ni][nj] = true;
                    pq.push({max(time,grid[ni][nj]),ni,nj});
                }
            }
        }
        return -1;
    }
};