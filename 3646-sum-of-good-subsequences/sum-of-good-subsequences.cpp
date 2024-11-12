#define ll long long 
class Solution {
public:
    int MOD = 1e9 + 7;
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n = nums.size();
        
        map<ll,ll> dp;
        map<ll,ll> count;
        ll res = 0;

        for(int i = 0 ; i < n ; i++) {
            if(dp.find(nums[i]-1) != dp.end()){
                ll temp = ((count[nums[i]-1]*nums[i])%MOD + dp[nums[i]-1])%MOD;
                dp[nums[i]] = (dp[nums[i]] + temp) % MOD;
                count[nums[i]] = (count[nums[i]] + count[nums[i]-1])%MOD ;
                res = (res + temp) % MOD;
                
            }
            if(dp.find(nums[i]+1) != dp.end()) {
                ll temp = ((count[nums[i]+1]*nums[i])%MOD + dp[nums[i]+1])%MOD;
                dp[nums[i]] = (dp[nums[i]] + temp) % MOD;
                count[nums[i]] = (count[nums[i]] + count[nums[i]+1])%MOD;
                res = (res + temp) % MOD;
            }
            count[nums[i]]++;
            dp[nums[i]] = (dp[nums[i]] + nums[i]) % MOD;
            res = (res + nums[i])% MOD;
            
        }
        return res;
    }
};