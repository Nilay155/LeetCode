class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        // j - i != nums[j] - nums[i] && i < j
        // Brute Force -> O(n^2)
        // Optimal Soln -> ?

        unordered_map<int,int> mpp;

        for(int j = 0 ; j < n ; j++) {
            mpp[nums[j]-j]++;
        }

        long long ans = 0;

        for(int i = 0 ; i < n ; i++) {
            int val = nums[i]-i;
            if(mpp.count(val)) {
                ans += n-mpp[val]-i;
            } else {
                ans += n-i-1;
            }
            // cout << ans << endl;
            mpp[val]--;
            if(mpp[val] == 0) mpp.erase(val);
        }
        return ans;
    }
};