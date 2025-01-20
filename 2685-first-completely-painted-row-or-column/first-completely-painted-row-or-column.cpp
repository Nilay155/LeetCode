class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int,vector<int>> mpp;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                mpp[mat[i][j]]={i,j};
            }
        }
        vector<int> col(m), row(n);
        // col -> n and row -> m
        for(int i = 0 ; i < n*m ; i++) {
            int rowIndex = mpp[arr[i]][0];
            int colIndex = mpp[arr[i]][1];
            col[colIndex]++;
            row[rowIndex]++;
            if(col[colIndex] == n || row[rowIndex] == m) return i;
        }
        return 0;
    }
};