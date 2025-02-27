class Solution {
public:
    int lenLongestFibSubseq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<vector<int>> dp(n,vector<int>(n,2));

        int maxLen = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = i ; j >= 0 ; j--) {
                int diff = nums[i] - nums[j];
                int idx = -1;
                if(diff < nums[j] && mpp.find(diff) != mpp.end()) {
                    idx = mpp[diff];
                }
                if(idx == -1) {
                    continue;
                } else {
                    dp[i][j] = max(dp[i][j],1 + dp[j][idx]);
                    maxLen = max(dp[i][j],maxLen);
                }
            }
            mpp[nums[i]] = i;
        }
        return maxLen > 2 ? maxLen : 0;
    }
};