class Solution {
public:
    int dp[305][305];
    int solve(vector<int> &nums,int left,int right) {
        if(left > right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int res = 0;

        for(int k = left ; k <= right ; k++) {
            int temp = nums[left-1] * nums[k] * nums[right+1];
            res = max(res,temp + solve(nums,left,k-1) + solve(nums,k+1,right));
        }
        return dp[left][right] = res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solve(nums,1,n-2);
    }
};