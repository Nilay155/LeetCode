class Solution {
private:
    pair<int,int> diameter(vector<vector<int>>&graph,int node,vector<bool>&vis) {
        
        vis[node] = true;
        int maxDistance = 0, nbrNode = node;
    
        for(int nbr : graph[node]) {
            if(!vis[nbr]) {
                auto [dist,k] = diameter(graph,nbr,vis);
                if(maxDistance < dist) {
                    maxDistance = dist;
                    nbrNode = k;
                }
            }
        }
        return {maxDistance + 1,nbrNode};
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> graph1(n + 1), graph2(m + 1);
        for(auto edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for(auto edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis1(n + 1,false), vis2(m + 1,false);

        auto [d1,node1] = diameter(graph1,0,vis1);
        vis1 = vector<bool> (n + 1,false);
        cout << d1 << " : " << node1 << "\n";
        
        auto [d2,node2] = diameter(graph1,node1,vis1);
        cout << d2 << " : " << node2 << "\n";
        
        auto [d3,node3] = diameter(graph2,0,vis2);
        vis2 = vector<bool> (m + 1,false);
        cout << d3 << " : " << node3 << "\n";
        
        auto [d4,node4] = diameter(graph2,node3,vis2);
        cout << d4 << " : " << node4 << "\n";
        
        // no of edges in the diameter = nodes - 1
        int k1 = d2 - 1, k2 = d4 - 1;
        int ans = max(k1,k2);

        if(k1&1) k1 = (k1 / 2) + 1;
        else k1 /= 2;

        if(k2&1) k2 = (k2 / 2) + 1;
        else k2 /= 2;
        
        return max(k1 + k2 + 1,ans);
    }
};