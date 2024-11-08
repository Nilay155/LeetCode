class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[101][201];

    int solve(vector<int> &locations,int s,int f,int fuel,int &n) {
        if(s == f && fuel >= 0) {
            if(dp[s][fuel] != -1) return dp[s][fuel];
            long long res = 1;
            for(int j = 0 ; j < n ; j++) {
                if(j != s) {
                    int temp = abs(locations[s]-locations[j]);
                    res = (res + solve(locations,j,f,fuel - temp,n)) % MOD;
                }
            }
            return dp[s][fuel] = res%MOD;
        }
        if(fuel < 0) return 0;
        if(dp[s][fuel] != -1) return dp[s][fuel];
        long long ans = 0;

        for(int j = 0 ; j < n ; j++) {
            if(j != s) {
                int temp = abs(locations[s]-locations[j]);
                ans = (ans + solve(locations,j,f,fuel - temp,n)) % MOD;
            }
        }
        return  dp[s][fuel] = ans%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(locations,start,finish,fuel,n);
    }
};