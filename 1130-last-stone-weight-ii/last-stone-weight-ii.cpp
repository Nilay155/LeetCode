class Solution {
public:
    int dp[3001][3001];
    int solve(vector<int> &nums,int i,int disc1,int disc2,int &n) {
        if(i >= n) return abs(disc1-disc2);
        if(dp[disc1][disc2] != -1) return dp[disc1][disc2];

        int op1 = solve(nums,i+1,disc1+nums[i],disc2,n);
        int op2 = solve(nums,i+1,disc1,disc2+nums[i],n);

        return dp[disc1][disc2] = min(op1,op2);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(),stones.end());
        memset(dp,-1,sizeof(dp));
        return solve(stones,0,0,0,n);
    }
};