class Solution {
public:
    long long int solve(vector<vector<int>> &nums,int &time,int i,int end,int &n,
                        vector<vector<long long int>> &dp) {
        if(end >= time) return 0;
        if(i >= n) return 1e9;
        if(dp[i][end] != -1) return dp[i][end];

        int pick = 1e9;
        if(nums[i][0] <= end) {
            pick = 1 + solve(nums,time,i+1,nums[i][1],n,dp);
        }
        
        int notPick = 0 + solve(nums,time,i+1,end,n,dp);
        
        return dp[i][end] = min(notPick,pick);
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        // minimum clips to cut -> [0,time] using clips
        int n = clips.size();
        sort(clips.begin(),clips.end());
        vector<vector<long long int>> dp(n,vector<long long int>(time+1,-1));
        long long int ans = solve(clips,time,0,0,n,dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};