class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> cnt(n,1);

        for(int i = n-2 ; i >= 0 ; i--) {
            for(int j = i+1 ; j < n ; j++) {
                if(nums[i] < nums[j]) {
                    if(dp[i] < dp[j] +1) {
                        // First Mapping Wala Case
                        cnt[i] = cnt[j];
                        dp[i] = dp[j] + 1;
                    }
                    else if(dp[j]+1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            
        }
        int lis = 0;
        for(int i = 0 ; i < n; i++) {
            lis = max(lis,dp[i]);
        }

        int res = 0;
        for(int i = 0 ; i < n ; i++) {
            if(dp[i] == lis) {
                res += cnt[i];
            }
        }
        return res;
    }
};