class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> arr; // To store apple positions
    int dp[51][51][11];

    // Check if there's at least one apple in the submatrix (r1, c1) to (r2-1, c2-1)
    bool check(int r1, int c1, int r2, int c2) {
        int res = 0;
        for (int i = r1; i < r2; i++) {
            for (int j = c1; j < c2; j++) {
                res += arr[i][j];
            }
        }
        return res > 0;  // Return true if there's at least one apple
    }

    // Recursive function to solve the problem
    int solve(vector<string> &pizza, int row, int col, int k, int &n, int &m) {
        if (k == 1) return check(row, col, n, m);  // If this is the last cut, check if there's an apple in this partition
        if (dp[row][col][k] != -1) return dp[row][col][k];

        int res = 0;

        // Try horizontal cuts
        for (int i = row + 1; i < n; i++) {
            if (check(row, col, i, m)) {  // Check if the upper partition has apples
                res = (res + solve(pizza, i, col, k - 1, n, m)) % MOD;  // Recur for the lower partition
            }
        }

        // Try vertical cuts
        for (int j = col + 1; j < m; j++) {
            if (check(row, col, n, j)) {  // Check if the left partition has apples
                res = (res + solve(pizza, row, j, k - 1, n, m)) % MOD;  // Recur for the right partition
            }
        }

        return dp[row][col][k] = res;
    }

    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();

        arr = vector<vector<int>>(n, vector<int>(m, 0));
        memset(dp, -1, sizeof(dp));

        // Populate the apple positions in the arr matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = (pizza[i][j] == 'A') ? 1 : 0;
            }
        }

        // Start the recursive process from the top-left corner (0, 0)
        return solve(pizza, 0, 0, k, n, m);
    }
};
