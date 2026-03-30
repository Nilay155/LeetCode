class Solution {
private:
    // int dp[51][51][101];
    // int f(int a,int b,vector<vector<int>> &costs,int i) {
    //     if(i >= costs.size()) 
    //         return 0;
    //     if(dp[a][b][i] != -1) return dp[a][b][i];

    //     int op1 = INT_MAX, op2 = INT_MAX;
    //     if(a) {
    //         op1 = min(op1,costs[i][0] + f(a - 1,b,costs,i + 1));
    //     }
    //     if(b) {
    //         op2 = min(op1,costs[i][1] + f(a,b - 1,costs,i + 1));
    //     }
    //     return dp[a][b][i] = min(op1,op2);
    // }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(); // n % 2 == 0
        // minimize cost n -> A and n -> B
        // memset(dp,-1,sizeof(dp));
        // return f(n / 2,n / 2,costs,0);
        // 1. Soln -> DP
        // 2. Soln -> Greedy ? 
        int a = n/2, b = n/2;
        sort(costs.begin(),costs.end(),[&](vector<int> &A,vector<int> &B) {

            return abs(A[0] - A[1]) < abs(B[0] - B[1]);
        });

        int ans = 0;
        for(int i = n - 1 ; i >= 0 ; i--) {
            if(a && b) {
                if(costs[i][0] >= costs[i][1]) {
                    b -= 1;
                    ans += costs[i][1];
                } else {
                    a -= 1;
                    ans += costs[i][0];
                }
            }
            else if(a) {
                a -= 1;
                ans += costs[i][0];
            }
            else if(b) {
                b -= 1;
                ans += costs[i][1];
            }
        }
        return ans;
    }
};