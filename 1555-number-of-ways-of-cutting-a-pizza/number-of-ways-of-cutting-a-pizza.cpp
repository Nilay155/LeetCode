class Solution {
private:
    int MOD = 1e9 + 7;
    // int dp[51][51][11];

    // int f(vector<vector<int>> &prefix,int r,int c,int k,int &n,int &m) {

    //     if(r < n && c < m && k == 1) {
    //         int x1 = r, y1 = c, x2 = n - 1, y2 = m - 1;
    //         int area = 0;

    //         if(x1 - 1 >= 0)
    //             area -= prefix[x1 - 1][y2];
    //         if(y1 - 1 >= 0)
    //             area -= prefix[x2][y1 - 1];
    //         if(x1 - 1 >= 0 && y1 - 1 >= 0)
    //             area += prefix[x1 - 1][y1 - 1];

    //         area += prefix[x2][y2];

    //         return area > 0 ? 1 : 0;
    //     }
        
    //     if(r >= n || c >= m || k <= 1)
    //         return 0;

    //     if(dp[r][c][k] != -1)
    //         return dp[r][c][k];

    //     int ans = 0;

    //     // horizontal cut
    //     for(int rr = r ; rr < n - 1 ; rr++) {
    //         int x1 = r, y1 = c, x2 = rr, y2 = m - 1;
    //         int area = 0;

    //         if(x1 - 1 >= 0)
    //             area -= prefix[x1 - 1][y2];
    //         if(y1 - 1 >= 0)
    //             area -= prefix[x2][y1 - 1];
    //         if(x1 - 1 >= 0 && y1 - 1 >= 0)
    //             area += prefix[x1 - 1][y1 - 1];
    //         area += prefix[x2][y2];

    //         if(area)
    //             ans = (ans + f(prefix,rr + 1,c,k - 1,n,m)) % MOD;

    //     }
    //     // vertical cut
    //     for(int cc = c ; cc < m - 1 ; cc++) {
    //         int x1 = r, y1 = c, x2 = n - 1, y2 = cc;

    //         int area = 0;

    //         if(x1 - 1 >= 0)
    //             area -= prefix[x1 - 1][y2];
    //         if(y1 - 1 >= 0)
    //             area -= prefix[x2][y1 - 1];
    //         if(x1 - 1 >= 0 && y1 - 1 >= 0)
    //             area += prefix[x1 - 1][y1 - 1];
    //         area += prefix[x2][y2];

    //         if(area)
    //             ans = (ans + f(prefix,r,cc + 1,k - 1,n,m)) % MOD;
    //     }
    //     return dp[r][c][k] = ans % MOD;
    // }
public:
    int ways(vector<string>& pizza, int K) {
        int n = pizza.size(), m = pizza[0].length();
        vector<vector<int>> prefix(n,vector<int>(m,0));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int val = (pizza[i][j] == 'A' ? 1 : 0);
                prefix[i][j] = val + (i - 1 >= 0 ? prefix[i - 1][j] : 0) 
                        + (j - 1 >= 0 ? prefix[i][j - 1] : 0) - (i - 1 >= 0 && j - 1 >= 0 ? prefix[i - 1][j - 1] : 0);
            }
        }
        // memset(dp,-1,sizeof(dp));
        // return f(prefix,0,0,k,n,m);

        vector<vector<vector<int>>> dp(K + 1,vector<vector<int>>(n,vector<int>(m,0)));

        for(int r = 0 ; r < n ; r++) {
            for(int c = 0 ; c < m ; c++) {
                int x1 = r, y1 = c, x2 = n - 1, y2 = m - 1;
                int area = 0;

                if(x1 - 1 >= 0)
                    area -= prefix[x1 - 1][y2];
                if(y1 - 1 >= 0)
                    area -= prefix[x2][y1 - 1];
                if(x1 - 1 >= 0 && y1 - 1 >= 0)
                    area += prefix[x1 - 1][y1 - 1];

                area += prefix[x2][y2];

                dp[1][r][c] = area > 0 ? 1 : 0;
            }
        }

        for(int k = 2 ; k <= K ; k++) {
            for(int r = n - 1 ; r >= 0 ; r--) {
                for(int c = m - 1 ; c >= 0 ; c--) {

                    int ans = 0;
                    // horizontal cut
                    for(int rr = r ; rr < n - 1 ; rr++) {
                        int x1 = r, y1 = c, x2 = rr, y2 = m - 1;
                        int area = 0;

                        if(x1 - 1 >= 0)
                            area -= prefix[x1 - 1][y2];
                        if(y1 - 1 >= 0)
                            area -= prefix[x2][y1 - 1];
                        if(x1 - 1 >= 0 && y1 - 1 >= 0)
                            area += prefix[x1 - 1][y1 - 1];
                        area += prefix[x2][y2];

                        if(area)
                            ans = (ans + dp[k - 1][rr + 1][c]) % MOD;

                    }
                    // vertical cut
                    for(int cc = c ; cc < m - 1 ; cc++) {
                        int x1 = r, y1 = c, x2 = n - 1, y2 = cc;

                        int area = 0;

                        if(x1 - 1 >= 0)
                            area -= prefix[x1 - 1][y2];
                        if(y1 - 1 >= 0)
                            area -= prefix[x2][y1 - 1];
                        if(x1 - 1 >= 0 && y1 - 1 >= 0)
                            area += prefix[x1 - 1][y1 - 1];
                        area += prefix[x2][y2];

                        if(area)
                            ans = (ans + dp[k - 1][r][cc + 1]) % MOD;
                    }
                    dp[k][r][c] = ans % MOD;
                }
            }
        }

        return dp[K][0][0];
    }
};