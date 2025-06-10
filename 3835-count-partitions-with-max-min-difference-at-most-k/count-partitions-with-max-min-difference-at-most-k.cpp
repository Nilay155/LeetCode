class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        multiset<int> ms;
        
        vector<int> dp(n+1,0);
        dp[0] = 1;
        long long prefixSum = 0;
        int l = 0, r = 0;
        while(r < n) {
            prefixSum = (prefixSum + dp[r]) % MOD;
            ms.insert(nums[r]);
            while(*prev(end(ms)) - *begin(ms) > k) {
                prefixSum = (prefixSum - dp[l] + MOD) % MOD;
                ms.erase(ms.find(nums[l]));
                l++;
            }
            dp[r+1] = prefixSum;
            r++;
        }
        return dp[n];
    }
};