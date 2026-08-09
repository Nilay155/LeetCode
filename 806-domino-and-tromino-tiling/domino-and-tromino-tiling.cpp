class Solution {
private:
    int MOD = 1e9 + 7;
    int dp[1001][2][2];
    int f(int i,bool a,bool b,int &n) {

        if(i >= n)
            return 1;
        if(dp[i][a][b] != -1)
            return dp[i][a][b];

        int c = 0;
        if(!a & b) c = 1;
        if(a & !b) c = 2;

        int ans = 0;

        // Domino tile horizontally
        if(n - i >= 2) { 
            if(!c)
                ans = (ans + f(i + 2,true,true,n)) % MOD;
            else if(c == 1) 
                ans = (ans + f(i + 1,true,false,n)) % MOD;
            else 
                ans = (ans + f(i + 1,false,true,n)) % MOD;
                
        }

        // Domino tile Veritically
        if(!c)
            ans = (ans + f(i + 1,true,true,n)) % MOD;

        // Tormino tile [2,1]
        if(n - i >= 2 && !c) {
            ans = (ans + f(i + 1,true,false,n)) % MOD;
            ans = (ans + f(i + 1,false,true,n)) % MOD;
        }
        // Tormino tile [1,2]
        if(n - i >= 2 && c) {
            ans = (ans + f(i + 2,true,true,n)) % MOD;
        }
        return dp[i][a][b] = ans;
    }
public:
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,true,true,n);
    }
};