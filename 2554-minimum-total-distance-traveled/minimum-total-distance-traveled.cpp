typedef long long ll;
class Solution {
private:
    vector<vector<vector<ll>>> dp;
    ll f(vector<int> &r,vector<vector<int>> &ff,int i,int j,int l) {

        if(i >= r.size()) return 0;
        if(j >= ff.size()) return 1e18;
        if(dp[i][j][l] != -1) 
            return dp[i][j][l];

        ll minCost = 1e18;
        if(l > 0) {
            ll distance = abs(r[i] - ff[j][0]);
            minCost = min(minCost,distance + f(r,ff,i + 1,j,l - 1));
        }
        minCost = min(minCost,0 + f(r,ff,i,j + 1,j + 1 < ff.size() ? ff[j + 1][1] : 0));
        return dp[i][j][l] = minCost;
    }
public:
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& ff) {
        int n = r.size(), m = ff.size();
        sort(r.begin(),r.end());
        sort(ff.begin(),ff.end());
        dp = vector<vector<vector<ll>>> (n,vector<vector<ll>>(m,vector<ll>(n + 1, -1)));
        return f(r,ff,0,0,ff[0][1]);
    }
};