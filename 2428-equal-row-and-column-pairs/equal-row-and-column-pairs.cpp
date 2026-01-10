class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++) { 
            // row => 0 to n-1
            int j = 0;
            for(int c = 0 ; c < n ; c++) {
                bool flag = true;
                for(int r = 0 ; r < n ; r++, j++) {
                    if(grid[r][c] != grid[i][j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans += 1;
                j = 0;
            }
        }
        return ans;
    }
};