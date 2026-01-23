class Solution {
private:
    int dp[1001][2001];
    int f(vector<vector<int>> &piles,int i,int k,int &n) {
        if(i >= n && k == 0) return 0;
        if(i >= n) return INT_MIN;
        if(dp[i][k] != -1) return dp[i][k];

        int notPick = f(piles,i+1,k,n);

        int ans = INT_MIN;
        for(int j = 0 ; j < min(k,(int)piles[i].size()) ; j++) {
            int rec = f(piles,i + 1,k - j - 1,n);
            if(rec != INT_MIN)
                ans = max(ans,piles[i][j] + rec);
        }
        return dp[i][k] = max(ans,notPick);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        // Prefix-Sum computations
        for(int i = 0 ; i < n ; i++) {
            for(int j = 1 ; j < piles[i].size() ; j++) {
                piles[i][j] += piles[i][j-1];
            }
        }
        return f(piles,0,k,n);
    }
};