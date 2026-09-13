class Solution {
private:
    int MOD = 1e9 + 7;
    int dp[5001][4][4][4];
    int f(int n,vector<vector<int>> &colorCombinations,int x,int y,int z) {
        if(n == 0)
            return 1;
        if(dp[n][x][y][z] != -1)
            return dp[n][x][y][z];

        int ans = 0;
        for(int i = 0 ; i < (int) colorCombinations.size() ; i++) {
            int nx = colorCombinations[i][0], ny = colorCombinations[i][1],
            nz = colorCombinations[i][2];
            if(nx != x && ny != y && nz != z) {
                ans = (ans + f(n - 1,colorCombinations,nx,ny,nz)) % MOD;
            }
        }
        return dp[n][x][y][z] = ans % MOD;
    }
public:
    int numOfWays(int n) {
        // r -> 1, y -> 2, g -> 3
        vector<vector<int>> colorCombinations = {
            {1,2,3},{1,3,2},{1,2,1},{1,3,1},
            {2,1,3},{2,3,1},{2,1,2},{2,3,2},
            {3,2,1},{3,1,2},{3,1,3},{3,2,3}
        };
        memset(dp,0,sizeof(dp));
        // return f(n,colorCombinations,0,0,0);

        // for(int x = 1 ; x <= 3 ; x++)
        //     for(int y = 1 ; y <= 3 ; y++)
        //         for(int z = 1 ; z <= 3 ; z++)
        //             dp[0][x][y][z] = 1;
        
        for(int i = 0 ; i < (int) colorCombinations.size() ; i++) {

            int nx = colorCombinations[i][0],
                ny = colorCombinations[i][1],
                nz = colorCombinations[i][2];

            dp[1][nx][ny][nz] = 1;
        }
        for(int k = 2 ; k <= n ; k++) {
            for(int x = 1 ; x <= 3 ; x++) {
                for(int y = 1 ; y <= 3 ; y++) {
                    for(int z = 1 ; z <= 3 ; z++) {
                        if(x == y || y == z)
                            continue;
                        int ans = 0;
                        for(int i = 0 ; i < (int) colorCombinations.size() ; i++) {

                            int nx = colorCombinations[i][0],
                                ny = colorCombinations[i][1],
                                nz = colorCombinations[i][2];

                            if((k == 1) || (nx != x && ny != y && nz != z)) {
                                ans = (ans + dp[k - 1][nx][ny][nz]) % MOD;
                            }
                        }
                        dp[k][x][y][z] = ans % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < (int) colorCombinations.size() ; i++) {
            int nx = colorCombinations[i][0],
                ny = colorCombinations[i][1],
                nz = colorCombinations[i][2];

            ans = (ans + dp[n][nx][ny][nz]) % MOD;
        }
        return ans;
    }
};