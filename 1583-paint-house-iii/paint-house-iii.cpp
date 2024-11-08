class Solution {
public:
    int dp[101][101][21];
    int solve(vector<int> &houses,vector<vector<int>> &cost,int m,int n,int target,int i,int prevHouse) {
        if(target == 0 && i >= m) return 0;
        if(i >= m || target < 0) return 1e9;
        if(dp[i][target][prevHouse] != -1) return dp[i][target][prevHouse];

        int res = 1e9;

        // Coloring the i-th not painted house
        if(!houses[i]) {
            for(int j = 0 ; j < n ; j++) {
                if(prevHouse == j+1) {
                    res = min(res, cost[i][j] + solve(houses,cost,m,n,target,i+1,prevHouse));
                } else {
                    res = min(res,cost[i][j] + solve(houses,cost,m,n,target-1,i+1,j+1));
                }
            }
        } else {
                if(prevHouse == houses[i]) {
                    res = min(res,solve(houses,cost,m,n,target,i+1,prevHouse));
                } else {
                    res = min(res,solve(houses,cost,m,n,target-1,i+1,houses[i]));
                }
        }
        return dp[i][target][prevHouse] = res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(houses,cost,m,n,target,0,0);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};