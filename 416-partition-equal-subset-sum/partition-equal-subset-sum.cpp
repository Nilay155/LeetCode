class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int num : nums) totalSum += num;

        if(totalSum & 1) return false;
        int halfSum = totalSum / 2;

        vector<vector<bool>> dp(n+1,vector<bool>(halfSum+1));

        for(int i = 0 ; i <= n ; i++) dp[i][0] = true;

        for(int i = 1 ; i <= n ; i++) {
            for(int t = 1 ; t <= halfSum ; t++) {
                if(nums[i-1] <= t) dp[i][t] = dp[i-1][t-nums[i-1]] | dp[i-1][t];
                else dp[i][t] = dp[i-1][t];
            }
        }
        return dp[n][halfSum];
    }
};