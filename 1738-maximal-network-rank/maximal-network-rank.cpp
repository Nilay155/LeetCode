class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> inDegree(n);
        for(auto road : roads) inDegree[road[0]] += 1, inDegree[road[1]] += 1;

        vector<vector<bool>> vis(n,vector<bool> (n,false));
        for(auto road : roads) {
            int u = road[0], v = road[1];
            vis[u][v] = vis[v][u] = true;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(i != j) {
                    int k1 = inDegree[i], k2 = inDegree[j];

                    if(vis[i][j]) 
                        ans = max(ans,k1 + k2 - 1);
                    else
                        ans = max(ans,k1 + k2);
                }
            }
        }
        return ans;
    }
};