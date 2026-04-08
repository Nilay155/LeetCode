typedef long long ll;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        int MOD = 1e9 + 7;
        for(int i = 0 ; i < m ; i++) {
            ll l = queries[i][0], r = queries[i][1];
            ll k = queries[i][2], v = queries[i][3];

            while(l <= r) {
                nums[l] = (nums[l] * v) % MOD;
                l += k;
            }
        }
        int XOR = 0;
        for(int i = 0 ; i < n ; i++) XOR ^= nums[i];
        return XOR;
    }
};