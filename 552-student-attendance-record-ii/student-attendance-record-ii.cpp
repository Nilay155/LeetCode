class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int n,int i,int A,int L,vector<vector<vector<int>>> &dp) {
        if(i > n) return 1;
        if(dp[i][A][L] != -1) return dp[i][A][L];

        // present hoona no issues
        int present = solve(n,i+1,A+0,0,dp);

        // late hone main some issues
        int late = 0;
        if(L < 2) late = solve(n,i+1,A+0,L+1,dp);

        // Absent hone main bahut issues hain'
        int absent = 0;
        if(A < 1) absent = solve(n,i+1,A+1,0,dp);

        long long int res = ((present + late)%MOD + absent)%MOD;
        return dp[i][A][L] = res;
    }   
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(n,1,0,0,dp)%MOD;

        // vector<vector<int>> dp(n+1,vector<int> (2,0));
        // dp[0][1] = dp[0][0] = 1;
        // long long res = 0;
        // for(int i = 1 ; i <= n ; i++) {

        //     res = ((present + absent)%MOD + late)%MOD;
        // }
        // return res;
    }
};