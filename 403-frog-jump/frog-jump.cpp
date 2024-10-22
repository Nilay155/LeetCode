class Solution {
public:
    bool solve(vector<int> &stones,int i,int k,int n,unordered_map<int,int> &mpp,
    vector<vector<int>> &dp) {
        if(i >= n-1) return 1;
        if(dp[i][k] != -1) return dp[i][k];

        int op0 = 0;
        int op1 = 0;
        int op2 = 0;

        if (mpp.find(stones[i] + k) != mpp.end()) {
            op0 = solve(stones,mpp[stones[i] + k], k,n,mpp,dp);
        }
        if(mpp.find(stones[i] + k + 1) != mpp.end()) {
            op1 = solve(stones,mpp[stones[i] + k + 1],k+1,n,mpp,dp);
        }
        if(k > 1 && mpp.find(stones[i] + k - 1) != mpp.end()) {
            op2 = solve(stones,mpp[stones[i] + k - 1],k-1,n,mpp,dp);
        }
        return dp[i][k] =  op1 || op2 || op0;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1 || stones[0] != 0) return false;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++) mpp[stones[i]] = i;

        vector<vector<int>> dp(n,vector<int>(2001,-1));
        return solve(stones,1,1,n,mpp,dp);
    }
};