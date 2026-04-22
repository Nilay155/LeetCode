class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // i , j , difference
        unordered_map<int,unordered_map<long long,int>> dp;
        for(int i = n - 2 ; i >= 0 ; i--) {
            for(int j = i + 1 ; j < n ; j++) {
                long long diff = (long long)nums[j] - (long long)nums[i];
                dp[i][diff] += 1;
            }
        }

        int ans = 0;
        for(int i = n - 3 ; i >= 0 ; i--) {
            for(int j = i + 1 ; j < n - 1 ; j++) {
                long long diff = (long long)nums[j] - (long long)nums[i];
                if(dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                    
                }
            }
        }
        return ans;
    }
};