class Solution {
private:
    int islandCount = 0;
    int dfs(vector<vector<int>> &grid,int x,int y,vector<vector<int>> &vis,vector<vector<int>> &islandSize,int &count,int marker) {
        
        vis[x][y] = islandCount;
        islandSize[x][y] = count;
        grid[x][y] = (marker == 2 ? 1 : 2);

        int ans = 1, n = grid.size();
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        for(int k = 0 ; k < 4 ; k++) {
            int ni = dx[k] + x, nj = dy[k] + y;
            if(ni >= 0 && ni < n && nj >= 0 && nj < n  
                && grid[ni][nj] == marker) {
                    ans = ans + dfs(grid,ni,nj,vis,islandSize,count,marker); 
            }
        }
        return ans;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        islandCount = 0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> islandSize(n,vector<int>(n,0));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    int count = 0;
                    islandCount += 1;
                    count = dfs(grid,i,j,vis,islandSize,count,1);
                    count = dfs(grid,i,j,vis,islandSize,count,2);
                }
            }
        }

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        int maxIsland = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                maxIsland = max(maxIsland,islandSize[i][j]);
                if(grid[i][j] == 1) continue;

                // means grid[i][j] == 0
                unordered_set<int> st;
                int totalSum = 0;
                for(int k = 0 ; k < 4 ; k++) {
                    int ni = dx[k] + i, nj = dy[k] + j;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                        if(!st.count(vis[ni][nj])) {
                            totalSum += islandSize[ni][nj];
                            st.insert(vis[ni][nj]);
                        }
                    }
                }
                maxIsland = max(maxIsland,totalSum + 1);
            }
        }
        return maxIsland;
    }
};