class Solution {
private:
    int dp[2001][2001];
    int f(vector<int> &nums,int i,int j,int &sum) {
        if(j-i+1 < 2) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int op1 = 0, op2 = 0, op3 = 0;
        if(sum == nums[i] + nums[j]) op1 = 1 + f(nums,i+1,j-1,sum);
        if(sum == nums[i] + nums[i+1]) op2 = 1 + f(nums,i+2,j,sum);
        if(sum == nums[j] + nums[j-1]) op3 = 1 + f(nums,i,j-2,sum);

        return dp[i][j] = max({op1,op2,op3});
    }
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int sum1 = nums[0] + nums[n-1];
        int m1 = f(nums,1,n-2,sum1) + 1;
        memset(dp,-1,sizeof(dp));
        int sum2 = nums[0] + nums[1];
        int m2 = f(nums,2,n-1,sum2) + 1;
        memset(dp,-1,sizeof(dp));
        int sum3 = nums[n-1] + nums[n-2];
        int m3 = f(nums,0,n-3,sum3) + 1;

        return max({m1,m2,m3});
    }
};