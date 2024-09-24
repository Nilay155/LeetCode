#define ll long long
class Solution {
public:
    ll MOD = 1e9 + 7;
    ll solve(int n,vector<ll> &dp) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2; 

        if(dp[n] != -1) return dp[n];

        ll domino = (solve(n-1,dp) + solve(n-2,dp))%MOD;
        ll tromino = 0;
        if(n >= 3) {
            for(ll i = 3 ; i <= n ; i++) {
                tromino += (2*solve(n-i,dp))%MOD;
            } 
        }
        return dp[n] = (((tromino + domino)%MOD))%MOD;
    }
    int numTilings(int n) {
        vector<ll> dp(n+1,-1);
        return solve(n,dp);
    }
};