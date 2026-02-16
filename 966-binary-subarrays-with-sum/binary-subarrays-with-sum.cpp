class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int l = 0, r = 0, sum = 0, count = 0;
        int ans = 0;

        while(r < n) {
            sum += nums[r];
            while(l <= r && (sum > goal || nums[l] == 0)) {
                if(nums[l] == 0) count += 1;
                else count = 0;
                sum -= nums[l];
                l += 1;
            }
            if(sum == goal) {
                if(goal == 0 && l > r) ans += count;
                else ans += 1 + count;
            }
            r += 1;
        }
        return ans;
    }
};