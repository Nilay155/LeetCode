class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n + 1, 0);
        for(auto edge : edges) inDegree[edge[0]] += 1, inDegree[edge[1]] += 1;

        vector<vector<bool>> connected(n + 1,vector<bool> (n + 1,false));
        for(auto edge : edges) 
            connected[edge[0]][edge[1]] = connected[edge[1]][edge[0]] = true;
        
        int minDegree = 1e9;
        for(int node1 = 1 ; node1 <= n ; node1 += 1) {
            for(int node2 = node1 + 1 ; node2 <= n ; node2 += 1) {
                for(int node3 = node2 + 1; node3 <= n ; node3 += 1) {

                    bool k1 = connected[node1][node2];
                    bool k2 = connected[node2][node3];
                    bool k3 = connected[node1][node3];

                    if(k1 && k2 && k3) {
                        // Potential-Trio
                        int totalIndegree = inDegree[node1] + inDegree[node2] + inDegree[node3] - 6;
                        minDegree = min(minDegree,totalIndegree);
                    }
                }
            }
        }
        return minDegree == 1e9 ? -1 : minDegree;
    }
};