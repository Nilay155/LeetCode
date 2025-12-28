class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<int> rows(n,INT_MAX), cols(m,INT_MIN);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m; j++) {
                rows[i] = min(rows[i],mat[i][j]);
                cols[j] = max(cols[j],mat[i][j]);
            }
        }

        vector<int> ans;
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ;j < m ; j++) {
                if(mat[i][j] == rows[i] && mat[i][j] == cols[j]) {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};