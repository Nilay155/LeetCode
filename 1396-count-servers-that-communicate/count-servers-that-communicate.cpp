class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rows(n),cols(m);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j]) {
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }

        int res = 0;
        for(int i = 0 ; i < n ; i++) {
            if(rows[i] > 1) res += rows[i];
        }
        // cout << res << endl;
        for(int i = 0 ; i < m ; i++) {
            if(cols[i] > 1) {
                for(int j = 0 ; j < n ; j++) {
                    if(rows[j] <= 1 && grid[j][i]) res += 1;
                }
            }
        }
        return res;
    }
};