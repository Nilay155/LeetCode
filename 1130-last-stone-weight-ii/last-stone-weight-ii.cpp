class Solution {
public:
    // int dp[3001][3001];
    int solve(vector<int> &nums,int i,int disc1,int disc2,int &n,vector<vector<int>> &dp) {
        if(i >= n) return abs(disc1-disc2);
        if(dp[disc1][disc2] != -1) return dp[disc1][disc2];

        int op1 = solve(nums,i+1,disc1+nums[i],disc2,n,dp);
        int op2 = solve(nums,i+1,disc1,disc2+nums[i],n,dp);

        return dp[disc1][disc2] = min(op1,op2);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(),stones.end());
        // memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(int num : stones) sum += num;
        vector<vector<int>> dp(sum+1,vector<int>(sum+1,-1));
        return solve(stones,0,0,0,n,dp);
    }
};