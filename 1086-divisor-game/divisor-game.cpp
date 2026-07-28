class Solution {
private:
    int dp[1001][3];
    bool f(int n,int turn) {
        if(dp[n][turn] != -1)
            return dp[n][turn];

        bool chance = false, ans1 = false,ans2 = true;
        for(int x = 1 ; x < n ; x++) {
            if(n % x == 0) {
                bool rec = f(n - x,turn == 1 ? 2 : 1);
                ans1 = ans1 | rec;
                ans2 = ans2 & rec;
                chance = true;
            }
        }

        if(!chance)
            return turn == 1 ? false : true;

        
        return dp[n][turn] = (turn == 1 ? ans1 : ans2);
    }
public:
    bool divisorGame(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n,1);
    }
};