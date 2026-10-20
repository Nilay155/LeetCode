class Solution {
private:
    int dp[2001][2001][4];
    int f(vector<int> &nums,int l,int r,int prev) {
        if(r - l + 1 <= 1)
            return 0;
        if(dp[l][r][prev] != -1)
            return dp[l][r][prev];

        int op1 = 0;
        int op2 = 0;
        int op3 = 0;

        if(prev == 0) {
            op1 = 1 + f(nums,l + 2,r,1);
            op2 = 1 + f(nums,l + 1,r - 1,2);
            op3 = 1 + f(nums,l,r - 2,3);
        } else if(prev == 1) {
            int prevSum = nums[l - 1] + nums[l - 2];
            if(nums[l] + nums[l + 1] == prevSum)
                op1 = 1 + f(nums,l + 2,r,1);
            if(nums[l] + nums[r] == prevSum) 
                op2 = 1 + f(nums,l + 1,r - 1,2);
            if(nums[r] + nums[r - 1] == prevSum) 
                op3 = 1 + f(nums,l,r - 2,3);
        } else if(prev == 2) {
            int prevSum = nums[l - 1] + nums[r + 1];
            if(nums[l] + nums[l + 1] == prevSum)
                op1 = 1 + f(nums,l + 2,r,1);
            if(nums[l] + nums[r] == prevSum) 
                op2 = 1 + f(nums,l + 1,r - 1,2);
            if(nums[r] + nums[r - 1] == prevSum) 
                op3 = 1 + f(nums,l,r - 2,3);
        } else {
            int prevSum = nums[r + 1] + nums[r + 2];
            if(nums[l] + nums[l + 1] == prevSum)
                op1 = 1 + f(nums,l + 2,r,1);
            if(nums[l] + nums[r] == prevSum) 
                op2 = 1 + f(nums,l + 1,r - 1,2);
            if(nums[r] + nums[r - 1] == prevSum) 
                op3 = 1 + f(nums,l,r - 2,3);
        }

        return dp[l][r][prev] = max({op1,op2,op3});
    }
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return f(nums,0,n - 1,0);
    }
};