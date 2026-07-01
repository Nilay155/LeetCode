class Solution {
private:
    int dp[100][101][101];
    int f(vector<int> &nums,int i,int op1,int op2,int &k,int &n) {

        if(i >= n)
            return 0;
        if(dp[i][op1][op2] != -1)
            return dp[i][op1][op2];
            
        // case1 : no operations
        int f1 = nums[i] + f(nums,i + 1,op1,op2,k,n);

        // case2: op1 operation
        int f2 = INT_MAX;
        if(op1 > 0)
            f2 = (nums[i] & 1 ? (nums[i]/2) + 1 : nums[i]/2) +
                 f(nums,i + 1,op1 - 1,op2,k,n);
        
        // case3 : op2 operation
        int f3 = INT_MAX;
        if(op2 > 0 && nums[i] >= k)
            f3 = nums[i] - k + f(nums,i + 1,op1,op2 - 1,k,n);
        
        // case4 : Both op1 and op2 operations
        int f4 = INT_MAX;
        if(op1 > 0 && op2 > 0) {
            // op1 followed by op2
            int u1 = (nums[i] & 1 ? (nums[i] / 2) + 1 : nums[i] / 2);
            if(u1 >= k)
                f4 = min(f4,u1 - k + f(nums,i + 1,op1 - 1,op2 - 1,k,n));
            
            // op2 followed by op1
            int u2 = nums[i];
            if(u2 >= k) {
                u2 -= k;
                u2 = (u2 & 1 ? (u2 / 2) + 1 : u2 / 2);
                f4 = min(f4,u2 + f(nums,i + 1,op1 - 1,op2 - 1,k,n));
            }
        }
        return dp[i][op1][op2] = min({f1,f2,f3,f4});
    }
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return f(nums,0,op1,op2,k,n);
    }
};