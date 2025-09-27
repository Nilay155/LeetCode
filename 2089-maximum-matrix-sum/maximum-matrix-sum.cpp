class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int negCount = 0, mini = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(matrix[i][j] < 0) negCount += 1;
                mini = min(mini,abs(matrix[i][j]));
            }
        }

        long long totalSum = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                totalSum += abs(matrix[i][j]);
            }
        }

        if(negCount&1) return totalSum - 2*mini;
        else return totalSum;
    }
};