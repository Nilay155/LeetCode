class Solution {
private:
    void imageRotation(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));

        int r = n - 1, c = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                ans[j][i] = matrix[r][c++];
            }
            r -= 1, c = 0;
        }
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                matrix[i][j] = ans[i][j];
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        // imageRotation(matrix);
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++)
            reverse(matrix[i].begin(),matrix[i].end());
        
        int r = n - 1, c = 0;
        while(r >= 0 && c < n) {
            int u = r,v = c;
            while(u >= 0 && v < n) {
                swap(matrix[u][c],matrix[r][v]);
                u -= 1, v += 1;
            }
            r -= 1, c += 1;
        }
        return ;
    }
};