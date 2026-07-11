class Solution {
private:
    int f(vector<vector<int>> &grid) {

        bool flag = false;
        for(int i = 0 ; i < 3 ; i++) {
            for(int j = 0 ; j < 3 ; j++) {
                if(!grid[i][j]) {
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
            return 0;
        
        
        int ans = INT_MAX;
        for(int i = 0 ; i < 3 ; i++) {
            for(int j = 0 ; j < 3 ; j++) {
                if(!grid[i][j]) {
                    for(int u = 0 ; u < 3 ; u++) {
                        for(int v = 0 ; v < 3 ; v++) {
                            if(grid[u][v] > 1) {
                                grid[u][v] -= 1;
                                grid[i][j] += 1;
                                ans = min(ans,abs(i - u) + abs(j - v) + f(grid));
                                grid[u][v] += 1;
                                grid[i][j] -= 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        return f(grid);
    }
};