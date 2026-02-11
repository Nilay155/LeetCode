class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0, r = 1,ans = 1;
        long long opr = 0;

        while(r < n) {
            opr += (long long)(nums[r] - nums[r - 1]) * (long long)(r - l);

            while(l < r && opr > k) {
                opr -= (nums[r] - nums[l]);
                l += 1;
            }
            ans = max(ans,r - l + 1);
            r += 1;
        }
        return ans;
    }
};