class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        int sum = 0, ans = 0;
        for(int r = 0 ; r < n ; r++) {
            sum += nums[r];

            if(mpp.find(sum - goal) != mpp.end()) {
                ans += mpp[sum - goal];
            }
            mpp[sum] += 1;
        }
        return ans;
    }
};