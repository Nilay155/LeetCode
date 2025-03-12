class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        // positive integers
        auto it1 = upper_bound(nums.begin(),nums.end(),0);

        // negative integers
        auto it2 = lower_bound(nums.begin(),nums.end(),0);
        int pos = 0, neg = 0;

        if(it1 != nums.end()) {
            int idx = it1-nums.begin();
            pos = n-idx;
        }
        if(it2 != nums.end()) {
            int idx = it2-nums.begin();
            if(nums[idx] >= 0) {
                idx -= 1;
            }
            if(idx >= 0) {
                neg = idx+1;
            }
        } else {
            neg = n;
        }
        return max(pos,neg);
    }
};