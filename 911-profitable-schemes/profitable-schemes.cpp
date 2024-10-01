class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(vector<int> &groups,vector<int> &profit,int num,int n,int i,int &m,int &minProfit,vector<vector<vector<long long int>>> &dp) {
        
        if(i >= m) {
            if(num >= minProfit) return 1;
            else return 0;
        }
        if(dp[i][n][num] != -1) return dp[i][n][num];

        int notPick = solve(groups,profit,num,n,i+1,m,minProfit,dp) % MOD;
        int pick = 0;

        if(groups[i] <= n) pick = solve(groups,profit,min(num+profit[i],minProfit),n-groups[i],i+1,m,minProfit,dp)%MOD;
        return dp[i][n][num] = (pick + notPick)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        // int temp = 0;
        // for(int num : group) temp += num;
        // cout << temp << endl;
       vector< vector<vector<long long int>>> dp(102,vector<vector<long long int>>(102,vector<long long int>(102,-1)));
        return solve(group,profit,0,n,0,m,minProfit,dp);
    }
};