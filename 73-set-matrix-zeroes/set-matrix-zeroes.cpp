class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Brute Force Track the rows and columns that have to be made 0 using rows and cols visited arrays -> O(n*m) time + O(n + m) space

        // Can be Optimized by using the first row and col as trackers for the arrays
        int n = matrix.size(), m = matrix[0].size();
        bool row0 = (matrix[0][0] == 0 ? true : false);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    if(i == 0) row0 = true;
                    else matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1 ; i < n ; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 0 ; j < m ; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0 ; i < m ; i++) {
            if(matrix[0][i] == 0) {
                for(int j = 0 ; j < n ; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if(row0) for(int i = 0 ; i < m ; i++) matrix[0][i] = 0;
        return ;
    }
};