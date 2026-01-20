class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;

        for(int l = 1 ; l <= n ; l++) {
            if(l-2 >= 2 || l == 2) {

                if(nums[l-2] == nums[l-1]) {
                    dp[l] = dp[l] | dp[l - 2];
                }
            }

            if(l-3 >= 2 || l == 3) {
                if(nums[l-2] == nums[l-1] && nums[l-2] == nums[l-3]) {
                    dp[l] = dp[l] | dp[l-3];
                }
                if(nums[l-1] == nums[l-2] + 1 && nums[l-2] == nums[l-3] + 1) {
                    dp[l] = dp[l] | dp[l-3];
                }
            }
        }
        return dp[n];
    }
};