class Solution {
public:
    // int dp[3001][3001];
    int solve(vector<int> &nums,int i,int disc,int sum,int &n,vector<vector<int>> &dp) {
        if(i >= n) return abs(sum-disc-disc);
        if(dp[i][disc] != -1) return dp[i][disc];

        int op1 = solve(nums,i+1,disc+nums[i],sum,n,dp);
        int op2 = solve(nums,i+1,disc,sum,n,dp);

        return dp[i][disc] = min(op1,op2);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(),stones.end());
        // memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(int num : stones) sum += num;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(stones,0,0,sum,n,dp);
    }
};