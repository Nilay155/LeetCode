class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> inDegree(n,0);
        for(auto road : roads) inDegree[road[0]] += 1, inDegree[road[1]] += 1;

        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(auto road : roads) vis[road[0]][road[1]] = vis[road[1]][road[0]] = true;

        int maxRank = 0;
        for(int node1 = 0 ; node1 < n ; node1 += 1) {
            for(int node2 = node1 + 1 ; node2 < n ; node2 += 1) {
                int totalIndegree = inDegree[node1] + inDegree[node2];
                if(vis[node1][node2] || vis[node2][node1]) totalIndegree -= 1;
                maxRank = max(maxRank,totalIndegree);
            }
        }
        return maxRank;
    }
};