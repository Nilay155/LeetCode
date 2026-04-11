class Solution {
private:
    bool check(vector<vector<int>> &grid) {
        bool flag = true;
        for(int i = 0 ; i < 3 ; i++) {
            for(int j = 0 ; j < 3 ; j++) {
                if(grid[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
    int minMoves(vector<vector<int>> &grid) {
        if(check(grid)) return 0;
        int mini = 1e9;

        for(int i = 0 ; i < 3 ; i++) {
            for(int j = 0 ; j < 3 ; j++) {
                if(grid[i][j] == 0) {
                    for(int u = 0 ; u < 3 ; u++) {
                        for(int v = 0 ; v < 3 ; v++) {
                            if(grid[u][v] > 1) {
                                int cost = abs(u - i) + abs(v - j);

                                grid[i][j] += 1;
                                grid[u][v] -= 1;
                                mini = min(mini, cost + minMoves(grid));
                                grid[u][v] += 1;
                                grid[i][j] -= 1;
                            }
                        }
                    }
                }
            }
        }
        return mini;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        return minMoves(grid);
    }
};