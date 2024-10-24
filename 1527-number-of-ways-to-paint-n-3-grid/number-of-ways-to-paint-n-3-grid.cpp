class Solution {
public:
    int MOD = 1e9 + 7;
    vector<string> s = {
        "123",
        "121",
        "212",
        "213",
        "132",
        "131",
        "231",
        "232",
        "321",
        "313",
        "312",
        "323"
    };
    int dp[5001][4][4][4];
    int solve(int n,int k,int a,int b,int c) {
        if(k == n) return 1;
        if(dp[k][a][b][c] != -1) return dp[k][a][b][c];

        int res = 0;
        for(int i = 0 ; i < 12 ; i++) { // Twelve No Ways to color every row
            if(k == 0) res = (res + solve(n,k+1,s[i][0]-'0',s[i][1]-'0',s[i][2]-'0')) % MOD;
            else {
                if(a == s[i][0]-'0' || b == s[i][1]-'0' || c == s[i][2]-'0') continue;
                else res = (res + solve(n,k+1,s[i][0]-'0',s[i][1]-'0',s[i][2]-'0')) % MOD;
            } 
        }
        return dp[k][a][b][c] = res;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,0,0);
    }
};