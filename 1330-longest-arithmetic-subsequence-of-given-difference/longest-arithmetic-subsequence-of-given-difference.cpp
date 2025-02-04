class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        int n = nums.size();

        vector<int> dp(2e5,0);

        for(int i = 0 ; i < n ; i++) {
            int ele = nums[i] + 100000;
            int val = (ele - diff);

            if(dp[val]) {
                dp[ele] = 1 + dp[val];
            } else {
                dp[ele] = 1;
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < dp.size() ; i++) ans = max(ans,dp[i]);
        return ans;
    }
};