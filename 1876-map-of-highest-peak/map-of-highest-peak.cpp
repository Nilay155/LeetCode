class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        queue<vector<int>> q;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(isWater[i][j]) {
                    q.push({i,j,0});
                    vis[i][j] = true;
                }
            }
        }

        int dx[] = {-1,0,0,1};
        int dy[] = {0,1,-1,0};

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p[0], j = p[1], val = p[2];
            
            ans[i][j] = val;
            for(int k = 0 ; k < 4 ; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
                    q.push({x,y,val+1});
                    vis[x][y] = true;
                }
            }
        }
        return ans;
    }
};