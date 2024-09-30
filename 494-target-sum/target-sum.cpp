class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum += num;
        if(target > sum || target < -sum) return 0;
        int dp[n+1][2*sum+1];
        memset(dp,0,sizeof(dp)); 

        if(nums[0] == 0) dp[1][sum+nums[0]] = dp[1][sum-nums[0]] = 2;
        else dp[1][sum+nums[0]] = dp[1][sum-nums[0]] = 1;

        for(int i = 2 ; i <= n ; i++) {
            for(int j = 0 ; j < 2*sum+1 ; j++) {
                if(j-nums[i-1] >= 0) {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
                if(j+nums[i-1] < 2*sum+1) {
                    dp[i][j] += dp[i-1][j+nums[i-1]];
                } else {
                    dp[i][j] += 0;
                }
            }
        }
        // for(int i = 0 ; i <= n ; i++) {
        //     for(int j = 0 ; j < 2*sum+1 ; j++) cout << dp[i][j] << "  ";
        //     cout <<endl;
        // }
        return dp[n][sum+target];
    }
};