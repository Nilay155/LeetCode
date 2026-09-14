class Solution {
private:
    
    bool f(vector<int> &nums,int i,int n,vector<int> &dp) {
        if(i >= n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];

        // window of size - 2
        bool op1 = (i + 1 < n ? nums[i] == nums[i + 1] ? f(nums,i + 2,n,dp) : false : false);

        // window of size - 3
        bool op2 = (i + 2 < n ? (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) ? f(nums,i + 3,n,dp) : false : false);

        bool op3 = (i + 2 < n ? (nums[i] + 1 == nums[i + 1]&& nums[i + 1] + 1 == nums[i + 2]) ? f(nums,i + 3,n,dp) : false : false);

        return dp[i] = op1 || op2 || op3;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(nums,0,n,dp);
    }
};