class Solution {
private:
    int MOD = 1e9 + 7;
    // int dp[100000][3];
    // int ways(string &str, int i, int count, int &n) {
    //     if (i >= n) return (count == 2);
    //     if (dp[i][count] != -1) return dp[i][count];

    //     int ans = 0;

    //     if(str[i] == 'S') {
    //         if(count == 2) {
    //             ans = (ans + ways(str,i+1,1,n)) % MOD;
    //         } else {
    //             ans = (ans + ways(str,i+1,count+1,n)) % MOD;
    //         }
    //     } else {
    //         if(count == 2) {
    //             ans = (ans + ways(str,i+1,count,n)) % MOD;
    //             ans = (ans + ways(str,i+1,0,n)) % MOD;
    //         } else {
    //             ans = (ans + ways(str,i+1,count,n)) % MOD;
    //         }
    //     }
    //     return dp[i][count] = ans;
    // }
    int tabulation(string &str,int &n) {
        int dp[100001][3];
        memset(dp,0,sizeof(dp));
        dp[n][2] = 1;

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int count = 0 ; count <= 2 ; count++) {

                if(str[i] == 'S') {
                    if(count == 2) {
                        dp[i][count] = (dp[i][count] + dp[i+1][1]) % MOD;
                    } else {
                        dp[i][count] = (dp[i][count] + dp[i+1][count + 1]) % MOD;
                    }
                } else {

                    if(count == 2) {
                        dp[i][count] = (dp[i][count] + dp[i+1][count]) % MOD;
                        dp[i][count] = (dp[i][count] + dp[i+1][0]) % MOD;
                    } else {
                        dp[i][count] = (dp[i][count] + dp[i+1][count]) % MOD;
                    }
                }
            }
        }
        return dp[0][0];
    }
public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        // memset(dp,-1,sizeof(dp));
        // return ways(corridor,0,0,n);
        return tabulation(corridor,n);
    }
};