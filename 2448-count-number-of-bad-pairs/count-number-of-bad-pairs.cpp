typedef long long ll;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        unordered_map<int,int> mpp;

        for(int i = 0 ; i < n ; i++) {
            int result = nums[i] - i;
            if(mpp.find(result) != mpp.end()) {
                ans += (i - mpp[result]);
            } else {
                ans += i;
            }
            mpp[result] += 1;
        }
        return ans;
    }
};