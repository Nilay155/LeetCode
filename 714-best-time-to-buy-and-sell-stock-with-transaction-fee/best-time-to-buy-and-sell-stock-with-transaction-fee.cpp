class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[0][0] = -nums[0]; // Buying
        for(int i = 1 ; i < n ; i++) {
            
            // Buying Case
            dp[i][0] = max(dp[i-1][0],-nums[i] + dp[i-1][1]);
            // Selling Case
            dp[i][1] = max(nums[i]-fee+dp[i-1][0],dp[i-1][1]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};