class Solution {
private:
    int dp[101][201];
    int MOD = 1e9 + 7;
    int f(vector<int> &locations,int curr,int &destination,int fuel,int n) {
        if(dp[curr][fuel] != -1) return dp[curr][fuel];

        int ans = 0;
        if(curr == destination) ans += 1;
        for(int j = 0 ; j < n ; j++) {
            if(j != curr && abs(locations[curr] - locations[j]) <= fuel) {
                ans = (ans + f(locations,j,destination,fuel - abs(locations[curr] - locations[j]),n)) % MOD;
            }
        }
        return dp[curr][fuel] = ans % MOD;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // memset(dp,-1,sizeof(dp));
        // return f(locations,start,finish,fuel,locations.size());
        int n = locations.size();
        vector<vector<int>> dp(n,vector<int>(fuel+1,0));

        for(int f = 0 ; f <= fuel ; f++) dp[finish][f] = 1;
        
        for(int f = 0 ; f <= fuel ; f++) {
            for(int i = 0 ; i < n ; i++) {
            

                for(int j = 0 ; j < n ; j++) {

                    if(i != j && abs(locations[i] - locations[j]) <= f) {
                        dp[i][f] = (dp[i][f] + dp[j][f - abs(locations[i] - locations[j])]) % MOD;
                    }
                }
            }
        }
        return dp[start][fuel];
    }
};