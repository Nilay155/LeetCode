class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(),m = grid[0].size();

        vector<vector<int>> prefix(n,vector<int>(m));

        for(int i = 0 ; i < n ; i++) {
            prefix[i][0] = grid[i][0] + ((i-1 >= 0) ? prefix[i-1][0] : 0);
            int p = grid[i][0];
            for(int j = 1 ; j < m ; j++) {
                p += grid[i][j];
                prefix[i][j] = p + ((i-1 >= 0) ? prefix[i-1][j] : 0);
            }
        }

        int ans = 0;
        for(int i = 0 ;  i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int sum = prefix[i][j];
                // if(i == 1 && j == 1) cout << sum << "   ";
                if(sum <= k) {
                    // cout << i << "  " << j << "\n"; 
                    ans += 1; 
                }
            }
        }
        return ans;
    }
};