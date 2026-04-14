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
        return ;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        imageRotation(matrix);
    }
};