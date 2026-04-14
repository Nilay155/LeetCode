class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m,-1);

        for(int i = 0 ; i < m ; i++) {
            int r = 0, c = i;
            while(r < n && c >= 0 && c < m) {
                int move = grid[r][c];
                if(move == 1) {
                    int nbr = c + 1 < m ? grid[r][c + 1] : -1;
                    if(nbr == -1) break;
                    r += 1, c += 1;
                } else {
                    // move == -1
                    int nbr = c - 1 >= 0 ? grid[r][c - 1] : 1;
                    if(nbr == 1) break;
                    r += 1, c -= 1;
                }
            }   
            if(r == n)
                ans[i] = c;
        }
        return ans;
    }
};