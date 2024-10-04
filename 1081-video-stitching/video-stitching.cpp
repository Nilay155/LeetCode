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
    int tabulation(vector<vector<int>> &nums,int time,int n) {
        vector<vector<int>> dp(n+1,vector<int>(time+1,201));
        for(int i = 0 ;i <= n ; i++) dp[i][0] = 0;

        // for(int i = 0 ; i < n ; i++) cout << nums[i][0] << "  :  " << nums[i][1] << endl;
        for(int i = 1 ; i <= n ; i++) {
            for(int t = 1 ; t <= time ; t++) {

                int pick = 201;
                int notPick = dp[i-1][t];
                if(t>=nums[i-1][0] && t<=nums[i-1][1] && nums[i-1][0] != nums[i-1][1]) {
                    pick = 1 + dp[i-1][nums[i-1][0]];
                
                }
                dp[i][t] = min(pick,notPick);
            }
        }

        // for(int i = 0 ; i <=n ; i++) {
        //     for(int t = 0 ; t <= time ; t++) cout << dp[i][t] << "  ";
        //     cout << endl;
        // }
        return dp[n][time];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        // minimum clips to cut -> [0,time] using clips
        int n = clips.size();
        sort(clips.begin(),clips.end());
        // vector<vector<long long int>> dp(n,vector<long long int>(time+1,-1));
        // long long int ans = solve(clips,time,0,0,n,dp);
        int ans = tabulation(clips,time,n);
        if(ans >= 201) return -1;
        else return ans;
    }
};