class Solution {
private:
    int dp[20][20];
    int f(int l,int r) {
        if(l >= r) 
            return 1;
        if(dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;
        for(int x = l ; x <= r ; x++) {
            int left = f(l,x - 1);
            int right = f(x + 1,r);
            ans += (left * right);
        }
        return dp[l][r] = ans;
    }
public:
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return f(1,n);
    }
};