class Solution {
private:
    long long compute(int n) {
        return 1LL*(n * (n-1))/2;
    }
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        int l = 0;
        long long ans = 0;
        long long pairs = 0;

        for(int r = 0 ; r < n ; r++) {
            
            if(mpp.find(nums[r]) != mpp.end()) {
                pairs -= compute(mpp[nums[r]]);
                mpp[nums[r]]++;
                pairs += compute(mpp[nums[r]]);
            } else {
                mpp[nums[r]]++;
                pairs += compute(mpp[nums[r]]);
            }
            while(pairs >= k && l < r) {
                ans += n-r;
                pairs -= compute(mpp[nums[l]]);
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                pairs += compute(mpp[nums[l]]);
                l++;
            }
        }
        return ans;
    }
};