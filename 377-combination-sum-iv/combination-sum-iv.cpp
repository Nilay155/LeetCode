class Solution {
private:
    int dp[1001];
    int f(vector<int> &nums,int target,int &n) {
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];

        int ans = 0; 
        for(int j = 0 ; j < n ; j++) {
            if(nums[j] <= target) 
                ans = (ans + f(nums,target - nums[j],n));
        }
        return dp[target] = ans;
    }
    int tabulation(vector<int> &nums,int &n,int &target) {

        memset(dp,0,sizeof(dp));
        dp[0] = 1;

        for(int t = 1 ; t <= target ; t++) {

            for(int j = 0 ; j < n ; j++) {
                if(nums[j] <= t)
                    dp[t] += dp[t - nums[j]];
            }
        }
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return f(nums,target,n);
    }
};