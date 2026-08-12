class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        
        vector<vector<bool>> dp(n + 1,vector<bool>(n + 1,false));
        vector<int> inDegree(n + 1,0);
        for(auto edge : edges) {
            dp[edge[0]][edge[1]] = true;
            dp[edge[1]][edge[0]] = true;
            inDegree[edge[0]] += 1;
            inDegree[edge[1]] += 1;
        }

        int mini = INT_MAX;
        for(int x = 1 ; x <= n ; x++) {
            for(int y = 1 ; y <= n ; y++) {
                if(x == y) continue;
                for(int z = 1 ; z <= n ; z++) {
                    if(y == z || x == z) continue;
                    bool k1 = dp[x][y], k2 = dp[y][z] , k3 = dp[x][z];
                    if(k1 && k2 && k3) {
                        int res = inDegree[x] + inDegree[y] + inDegree[z];
                        mini = min(mini,res - 6);
                    }
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};