typedef long long ll;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();

        sort(nums.begin(),nums.end());
        vector<ll> prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i = 1 ; i < n ; i++) prefixSum[i] = nums[i] + prefixSum[i - 1];
        vector<ll> ans(m);
        for(int i = 0 ; i < m ; i++) {
            ll qq = queries[i];
            int q = queries[i];
            int ub = upper_bound(nums.begin(),nums.end(),q) - nums.begin();
            int lb = ub - 1;
            ll backSum = 0, forwardSum = 0;

            if(lb >= 0) 
                backSum += prefixSum[lb];
            if(ub != n) 
                forwardSum += prefixSum[n - 1] - ((ub - 1 >= 0) ? prefixSum[ub - 1] : 0);

            ll expectedBackSum = (ll)(lb + 1) * qq;
            ll expectedFrontSum = (ll)(n - ub) * qq;

            ll operations = expectedBackSum - backSum + forwardSum - expectedFrontSum;
            ans[i] = operations;

        }
        return ans;
    }
};