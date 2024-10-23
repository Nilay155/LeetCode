class Solution {
public:
    int MOD = 1e9 + 7;
    long long int dp[101][101];
    long long int solve(int n,int goal,int k,int songs) {
        if(songs == n && goal == 0) return 1;
        if(songs > n || goal == 0) return 0;
        if(dp[goal][songs] != -1) return dp[goal][songs];

        // Picking a new song
        long long int res = ((n-songs) * solve(n,goal-1,k,songs+1))%MOD;

        if(songs > k) res = (res + (songs-k) * solve(n,goal-1,k,songs)) % MOD;
        res %= MOD;
        return dp[goal][songs] = res;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,goal,k,0);
    }
};