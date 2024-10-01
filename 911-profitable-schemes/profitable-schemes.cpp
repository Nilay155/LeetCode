class Solution {
public:
    int totalPeople;
    int groupSize;
    int minProfit;
    int dp[101][101][101];
    int mod = 1e9 + 7;
    int solve(int i, int currProfit, int currPeople, vector<int>& group, vector<int>& profit){
        if(currPeople>totalPeople){
            return 0;
        }
        if(i == groupSize){
            if(currProfit == minProfit){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[i][currProfit][currPeople]!= -1) return dp[i][currProfit][currPeople];
        int take = solve(i+1, min(currProfit + profit[i], minProfit), currPeople+group[i], group, profit);
        int nottake = solve(i+1, currProfit, currPeople, group, profit);

        return dp[i][currProfit][currPeople] = (take + nottake)%mod;
    }
    int profitableSchemes(int n, int mini, vector<int>& group, vector<int>& profit) {
        totalPeople = n;
        groupSize = group.size();
        minProfit = mini;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, group, profit);
    }
};