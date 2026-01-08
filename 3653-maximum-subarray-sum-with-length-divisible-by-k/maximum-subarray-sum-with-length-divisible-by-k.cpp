typedef long long ll;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,ll> remainders;
        remainders[0] = 0LL;

        vector<ll> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++) prefix[i] = nums[i] + prefix[i-1];

        ll ans = LLONG_MIN;
        for(int i = 0 ; i < n ; i++) {
            int rem = (i+1) % k;
            int prev = (i - k);
            ll currSum = prefix[i] - ((prev >= 0) ? prefix[prev] : 0);

            if(remainders.find(rem) != remainders.end()) {
                ll prevSum = 0;
                if(prev+1 >= k) prevSum = remainders[rem];
                ll res = max(prevSum + currSum,currSum);
                remainders[rem] = res;
                ans = max(ans,remainders[rem]);
            } else {
                remainders[rem] = currSum;
            }
        }
        return ans;
    }
};