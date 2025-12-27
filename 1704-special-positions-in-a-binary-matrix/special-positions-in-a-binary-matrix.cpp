class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        vector<int> rows(n,0), cols(m,0);

        for(int r = 0 ; r < n ; r++) {
            for(int c = 0 ; c < m ; c++) {
                rows[r] += mat[r][c];
                cols[c] += mat[r][c];
            }
        }

        int ans = 0;
        for(int r = 0 ; r < n ; r++) {
            for(int c = 0 ; c < m ; c++) {

                if(mat[r][c] == 1 && rows[r] == 1 && cols[c] == 1) ans += 1;
            }
        }
        return ans;
    }
};