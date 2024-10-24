class Solution {
public:
    int dp[301][11];
    int solve(vector<int> &nums,int days,int i) {
        if(i >= nums.size() && days == 0) return 0;
        if(i >= nums.size() || days < 0) return 1e9;
        if(dp[i][days] != -1) return dp[i][days];

        int ans = 1e9 + 7;
        int maxi = 0;

        for(int j = i ; j < nums.size() ; j++) {
            maxi = max(maxi,nums[j]);
            int rec = maxi + solve(nums,days-1,j+1);
            ans = min(ans,rec);
        }
        return dp[i][days] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // Have to divide the jobDifficulty into d-1 partitions and find the optimal answer
        memset(dp,-1,sizeof(dp));
        int res = solve(jobDifficulty,d,0);
        if(res == 1e9 + 7) return -1;
        else return res;
    }
};