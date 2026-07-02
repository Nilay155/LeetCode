class Solution {
private:
    // int dp[100][101][101];
    // int f(vector<int> &nums,int i,int op1,int op2,int &k,int &n) {

    //     if(i >= n)
    //         return 0;
    //     if(dp[i][op1][op2] != -1)
    //         return dp[i][op1][op2];

    //     // case1 : no operations
    //     int f1 = nums[i] + f(nums,i + 1,op1,op2,k,n);

    //     // case2: op1 operation
    //     int f2 = INT_MAX;
    //     if(op1 > 0)
    //         f2 = (nums[i] & 1 ? (nums[i]/2) + 1 : nums[i]/2) +
    //              f(nums,i + 1,op1 - 1,op2,k,n);
        
    //     // case3 : op2 operation
    //     int f3 = INT_MAX;
    //     if(op2 > 0 && nums[i] >= k)
    //         f3 = nums[i] - k + f(nums,i + 1,op1,op2 - 1,k,n);
        
    //     // case4 : Both op1 and op2 operations
    //     int f4 = INT_MAX;
    //     if(op1 > 0 && op2 > 0) {
    //         // op1 followed by op2
    //         int u1 = (nums[i] & 1 ? (nums[i] / 2) + 1 : nums[i] / 2);
    //         if(u1 >= k)
    //             f4 = min(f4,u1 - k + f(nums,i + 1,op1 - 1,op2 - 1,k,n));
            
    //         // op2 followed by op1
    //         int u2 = nums[i];
    //         if(u2 >= k) {
    //             u2 -= k;
    //             u2 = (u2 & 1 ? (u2 / 2) + 1 : u2 / 2);
    //             f4 = min(f4,u2 + f(nums,i + 1,op1 - 1,op2 - 1,k,n));
    //         }
    //     }
    //     return dp[i][op1][op2] = min({f1,f2,f3,f4});
    // }
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        // memset(dp,-1,sizeof(dp));
        // return f(nums,0,op1,op2,k,n);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(op1 + 1,vector<int>(op2 + 1,1e9)));

        for(int o1 = 0 ; o1 <= op1 ; o1++) {
            for(int o2 = 0 ; o2 <= op2; o2++) {
                    int i = 0;
                    if(o1 && o2) {
                        // op1 -> op2
                        int temp = (nums[i] + 1) / 2;
                        if(temp >= k) {
                            temp -= k;
                            dp[i][o1][o2] = min(dp[i][o1][o2],temp);
                        } 
                        
                        // op2 -> op1
                        if(nums[i] >= k) {
                            temp = nums[i] - k;
                            temp = (temp + 1) / 2;
                            dp[i][o1][o2] = min(dp[i][o1][o2],temp);
                        } 
                        
                    } 
                    if(o1) {
                        int temp = (nums[i] + 1) / 2;
                        dp[i][o1][o2] = min(dp[i][o1][o2], temp);
                    } 
                    if(o2) {
                        int temp = 1e9;
                        if(nums[i] >= k) {
                            temp = nums[i] - k;
                            dp[i][o1][o2] = min(dp[i][o1][o2],temp);
                        }
                    }
                    dp[i][o1][o2] = min(dp[i][o1][o2],nums[i]);
                    
            }
        }

        for(int i = 1 ; i < n ; i++) {
            for(int o1 = 0 ; o1 <= op1 ; o1++) {
                for(int o2 = 0 ; o2 <= op2; o2++) {

                    if(o1 && o2) {
                        // op1 -> op2
                        int temp = (nums[i] + 1) / 2;
                        if(temp >= k) {
                            temp -= k;
                            dp[i][o1][o2] = min(dp[i][o1][o2], 
                                    temp + dp[i - 1][o1 - 1][o2 - 1]);
                        }
                        
                        // op2 -> op1
                        if(nums[i] >= k) {
                            temp = nums[i] - k;
                            temp = (temp + 1) / 2;
                            dp[i][o1][o2] = min(dp[i][o1][o2],
                                    temp + dp[i - 1][o1 - 1][o2 - 1]);
                        } 
                    }
                    if(o1) {
                        int temp = (nums[i] + 1) / 2;
                        dp[i][o1][o2] = min(dp[i][o1][o2], temp + 
                                            dp[i - 1][o1 - 1][o2]);
                    }
                    if(o2) {
                        int temp = 1e9;
                        if(nums[i] >= k) {
                            temp = nums[i] - k;
                             dp[i][o1][o2] = min(dp[i][o1][o2],temp +
                                            dp[i - 1][o1][o2 - 1]);
                        } 
                    }
                    
                    dp[i][o1][o2] = min(dp[i][o1][o2],nums[i]   +                 dp[i - 1][o1][o2]);
                    
                }
            }
        }

        return dp[n - 1][op1][op2];
    }
};