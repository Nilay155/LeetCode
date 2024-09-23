class Solution {
public:
    int func(vector<int> &nums,int i,int sign,int &n,vector<vector<int>> &dp) {
        if(i >= n) return 0;
        if(dp[i][sign] != -1) return dp[i][sign];

        int notPick = 0 + func(nums,i+1,sign,n,dp);
        int pick = 0;
    
        if(sign == 0) {
            if(nums[i]-nums[i-1] != 0)
                pick = 1 + func(nums,i+1,(nums[i]-nums[i-1] < 0) ? 2 : 1,n,dp);
        } else {
            if(nums[i]-nums[i-1] < 0 && sign == 1) {
                pick = 1 + func(nums,i+1,2,n,dp);
            } else if(nums[i]-nums[i-1] > 0 && sign == 2) {
                pick = 1 + func(nums,i+1,1,n,dp);
            }
        }
        return dp[i][sign] = max(notPick,pick);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(3,-1));
        // return func(nums,0,0,n,dp);

        vector<vector<int>> dp(n,vector<int>(2,0)); // 0 -> positive and 1 -> negative

        for(int i = 1 ; i < n ; i++) {
            int pick = 0;
            int notPick = 0;

            if(nums[i]-nums[i-1] > 0) {
                pick = 1 + dp[i-1][1];
                notPick = 0 + dp[i-1][0];
                dp[i][0] = max(pick,notPick);
            } else if(nums[i]-nums[i-1] < 0){
                pick = 1 + dp[i-1][0];
                notPick = 0 + dp[i-1][1];
                dp[i][1] = max(pick,notPick);
            } else {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
        }
        for(int i = 0 ; i < n ; i++) {
            cout << dp[i][0] << "  :  " << dp[i][1] << endl;
        }
        return 1 + max(dp[n-1][0],dp[n-1][1]);
    }
};