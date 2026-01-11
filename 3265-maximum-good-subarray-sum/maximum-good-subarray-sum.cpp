class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++) prefix[i] = nums[i] + prefix[i-1];

        unordered_map<int,long long> mpp;
        long long ans = LLONG_MIN;

        for(int i = 0 ; i < n ; i++) {

            int k1 = k + nums[i], k2 = nums[i] - k;
            
            if(mpp.find(k1) != mpp.end()) {
                ans = max(ans,(long long)(prefix[i] - ((mpp[k1]-1 >= 0) ? prefix[mpp[k1]-1] : 0)));
            }
            if(mpp.find(k2) != mpp.end()) {
                ans = max(ans,(long long)(prefix[i] - ((mpp[k2]-1 >= 0) ? prefix[mpp[k2]-1] : 0)));
            }

            if(mpp.find(nums[i]) != mpp.end()) {
                int prev = mpp[nums[i]];
                if(prefix[i-1] - ((prev-1 >= 0) ? prefix[prev-1] : 0) >= 0) {
                    mpp[nums[i]] = prev;
                } else {
                    mpp[nums[i]] = i;
                }
            } else {
                mpp[nums[i]] = i;
            }
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};