class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int sum = 0;

        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
            int r = sum % k;

            if(mpp.find(r) != mpp.end()) {
                int prev = mpp[r];
                if(i - prev  >= 2)
                    return true;
            } else {
                mpp[r] = i;
            }
        }
        return false;
    }
};