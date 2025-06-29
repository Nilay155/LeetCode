typedef long long ll;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        
        vector<int> pow2(n+1, 1);
        for(int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i-1]*2LL) % MOD;
        }

        sort(nums.begin(), nums.end());

        int l = 0, r = n - 1;
        ll ans = 0;
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                ans = (ans + pow2[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
