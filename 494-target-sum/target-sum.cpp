class Solution {
private:
    int f(vector<int> &nums,int target,int i) {
        if(target == 0 && i == 0) return 1;
        if(i == 0) return 0;

        // target can be negative so normalization has to be applied
        // if(dp[i][target + normalizer] != -1) return dp[i][target + normalizer];

        return f(nums,target + nums[i-1],i-1) + f(nums,target - nums[i-1],i-1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // return f(nums,target,n);

        int totalSum = 0;
        for(int num : nums) totalSum += num;
        if(target > totalSum || target < -totalSum) return 0;

        vector<vector<int>> dp(n + 1, vector<int> (2*totalSum + 1,0));

        int normalizer = totalSum;
        dp[0][normalizer] = 1;

        for(int i = 1 ; i <= n ; i++) {
            for(int t = -totalSum ; t <= totalSum ; t++) {

                // adding
                if(t + nums[i-1] <= totalSum) {
                    dp[i][t + normalizer] = dp[i-1][t + nums[i-1] + normalizer];
                }
                // subtracting
                if(t - nums[i-1] >= -totalSum) {
                    dp[i][t + normalizer] += dp[i-1][t - nums[i-1] + normalizer];
                }
            }
        }
        return dp[n][target + normalizer];
    }
};