class Solution {
private:
    int dfs(vector<vector<int>> &graph,vector<bool> &vis,int node) {
        
        vis[node] = true;
        int length = 0;

        for(int nbr : graph[node]) {
            if(!vis[nbr]) {
                length = 1 + dfs(graph,vis,nbr);
            }
        }
        return length;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n);
        vector<int> inDegree(n);
        for(int i = 0 ; i < n ; i++) {
            int e = edges[i];
            if(e == -1) continue;
            graph[i].push_back(e);
            inDegree[e] += 1;
        }

        // 1. Topological Sort Algorithm
        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        vector<bool> vis(n,false);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            vis[node] = true;
            for(int nbr : graph[node]) {
                inDegree[nbr] -= 1;
                if(inDegree[nbr] == 0)
                    q.push(nbr);
            } 
        }
        // Nodes potentially a part of a cycle
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) 
                q.push(i);
        }
        if(q.empty())
            return -1;
        
        // A potential Cycle
        int longestCycle = -1;
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) 
                longestCycle = max(longestCycle,dfs(graph,vis,i) + 1);
        }
        return longestCycle;
    }
};