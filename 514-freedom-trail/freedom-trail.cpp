class Solution {
public:
    int n = 0;
    int dp[101][101];
    unordered_map<char,vector<int>> mpp;
    int solve(string ring,string key,int i,int j) {
        if(j >= key.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;
        for(int idx : mpp[key[j]]) {
            
            int clockWise = 1e9;
            int anticlockWise = 1e9;
            if(idx >= i) {
                clockWise = min(clockWise,idx-i);
                anticlockWise = min(anticlockWise,n-idx+i);
            } else {
                clockWise = min(clockWise,i-idx);
                anticlockWise = min(anticlockWise,n-i+idx);
            }

            ans = min(ans,1 + anticlockWise + solve(ring,key,idx,j+1));
            ans = min(ans,1 + clockWise + solve(ring,key,idx,j+1));
        }
        return dp[i][j] = ans;
    }
    int findRotateSteps(string ring, string key) {
        n = ring.size();
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < n ; i++) mpp[ring[i]].push_back(i);
        return solve(ring,key,0,0);
    }
};