class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0,sum = 0;
        int l = 0, r = 0;

        while(r < n) {
            sum += nums[r];
            while(l <= r && sum * (long long)(r - l + 1) >= k) {
                sum -= nums[l];
                l += 1;
            }
            ans += (r - l + 1);
            r += 1;
        }
        return ans;
    }
};