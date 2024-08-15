class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &cuts,int i,int j){

        // Base-Case -> when no more cuts can be done
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;

        // Partition In All Possible Ways
        for(int k = i ; k < j ; k++) {
            int rec = (cuts[j]-cuts[i-1]) + solve(cuts,i,k) + solve(cuts,k+1,j);
            mini = min(rec,mini);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m = cuts.size();
        sort(cuts.begin(),cuts.end());
        dp = vector<vector<int>> (m+1,vector<int> (m+1,-1));
        return solve(cuts,1,m-1);
    }
};