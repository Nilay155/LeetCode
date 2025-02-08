class Solution {
public:
    vector<vector<int>> cache;
    bool check(int x,int y,int n,int m) {
        if(x >= 0 && x < n && y >= 0 && y < m) return true;
        else return false;
    }
    int dfs(vector<vector<int>> &matrix,int x,int y,vector<vector<int>> &vis,int prev,int &n,int &m) {
        
        if(cache[x][y] != -1) return cache[x][y];
        // vis[x][y] = 1;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};

        int ans = 1;
        for(int i = 0 ; i < 4 ; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(check(newX,newY,n,m) && !vis[newX][newY] && prev < matrix[newX][newY]) {
                int temp = 1 + dfs(matrix,newX,newY,vis,matrix[newX][newY],n,m);
                ans = max(ans,temp);
            }
        }
        // vis[x][y] = 0;
        return cache[x][y] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        cache = vector<vector<int>> (n,vector<int>(m,-1));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                res = max(res,dfs(matrix,i,j,vis,matrix[i][j],n,m));
            }
        }
        return res;
    }
};