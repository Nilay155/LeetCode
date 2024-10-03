class Solution {
public:
    double solve(int m,int n,int k,int row,int col) {
        if(row < 0 || col < 0 || row > m || col > n || k < 0) return 0;
        if(k == 0) return 1;

        double op1 = 0.1250 * solve(m,n,k-1,row-2,col+1);
        double op2 = 0.1250 * solve(m,n,k-1,row-1,col+2);
        double op3 = 0.1250 * solve(m,n,k-1,row+1,col+2);
        double op4 = 0.1250 * solve(m,n,k-1,row+2,col+1);
        double op5 = 0.1250 * solve(m,n,k-1,row+2,col-1);
        double op6 = 0.1250 * solve(m,n,k-1,row+1,col-2);
        double op7 = 0.1250 * solve(m,n,k-1,row-1,col-2);
        double op8 = 0.1250 * solve(m,n,k-1,row-2,col-1);

        double ans = op1+op2+op3+op4+op5+op6+op7+op8;
        return ans;
    }
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
    double tabulation(int m,int n,int k,int row,int col) {
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        dp[row][col] = 1;
        vector<vector<int>> moves = 
        {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        for(int move = 1 ; move <= k ; move++) {
            vector<vector<double>> next(m+1,vector<double>(n+1,0));

            for(int i = 0 ; i <= m ; i++) {
                for(int j = 0 ; j <= n ; j++) {
                    for (const auto& m : moves) {
                        int newR = i + m[0];
                        int newC = j + m[1];
                        if (isValid(newR, newC, n+1)) {
                            next[i][j] += dp[newR][newC] / 8.0;
                        }
                    }
                }
            }
            dp = next;
        }
        double probability = 0;
        for (int r = 0; r <= n; r++) {
            for (int c = 0; c <= n; c++) {
                probability += dp[r][c];
                cout << dp[r][c] << "  ";
            }cout << endl;
        }

        return probability;
    }
    double knightProbability(int n, int k, int row, int column) {
        return tabulation(n-1,n-1,k,row,column);
    }
};