class Solution {
public:
    map<int,int> mpp;
    int solve(vector<int> &arr,int i,int n,vector<int> &dp) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int notPick = 0 + solve(arr,i+1,n,dp);

        int pick = mpp[arr[i]]*arr[i];
        if(i+1 < n && arr[i+1]-1 != arr[i]) {
            pick += solve(arr,i+1,n,dp);
        } else {
            pick += solve(arr,i+2,n,dp);
        }

        return dp[i] = max(pick,notPick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++) {
            mpp[nums[i]]++;
        }
        vector<int> arr;
        for(auto& it : mpp) {
            arr.push_back(it.first);
        }
        int m = arr.size();
        // vector<int> dp(m+1,-1);
        // return solve(arr,0,m,dp);

        vector<int> dp(m,0);
        dp[0] = mpp[arr[0]]*arr[0];

        for(int i = 1 ; i < m ; i++) {

            int pick = 0;
            int notPick = 0;

            if(arr[i]-1 != arr[i-1]) {
                pick = mpp[arr[i]]*arr[i] + dp[i-1];
                notPick = 0 + dp[i-1];
            } else {
                pick = mpp[arr[i]]*arr[i] + ((i >= 2) ? dp[i-2] : 0);
                notPick = 0 + dp[i-1];
            }
            dp[i] = max(pick,notPick);
        }
        return dp[m-1];
    }
};