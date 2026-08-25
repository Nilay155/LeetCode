class Solution {
private:
    int dp[101][101][21];
    int f(vector<int> &houses,vector<vector<int>> &cost,int &target,int i,int k,int prevColor) {

        if(i >= houses.size() && k == target) 
            return 0;
        
        if(i >= houses.size() || k > target)
            return 1e9;
        
        if(dp[i][k][prevColor] != -1)
            return dp[i][k][prevColor];
        
        int n = cost[i].size();

        int ans = 1e9;
        if(houses[i] != 0) {
            ans = f(houses,cost,target,i + 1,(i - 1 >= 0 ? (houses[i] == prevColor ? k : k + 1) : (k) ), houses[i]);
        } else {
            for(int j = 0 ; j < n ; j++) {
                int rec = cost[i][j] + f(houses,cost,target,i + 1,(i - 1 >= 0 ? (j+1 == prevColor ? k : k + 1) : (k) ), j + 1);
                ans = min(ans,rec);
            }
        }
        return dp[i][k][prevColor] = ans;

    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int costt = f(houses,cost,target,0,1,0);
        return costt == 1e9 ? -1 : costt;
    }
};