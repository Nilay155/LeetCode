class Solution {
private:
    int dp[51][51][101];
    int f(int a,int b,vector<vector<int>> &costs,int i) {
        if(i >= costs.size()) 
            return 0;
        if(dp[a][b][i] != -1) return dp[a][b][i];

        int op1 = INT_MAX, op2 = INT_MAX;
        if(a) {
            op1 = min(op1,costs[i][0] + f(a - 1,b,costs,i + 1));
        }
        if(b) {
            op2 = min(op1,costs[i][1] + f(a,b - 1,costs,i + 1));
        }
        return dp[a][b][i] = min(op1,op2);
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(); // n % 2 == 0
        // minimize cost n -> A and n -> B
        memset(dp,-1,sizeof(dp));
        return f(n / 2,n / 2,costs,0);
    }
};