class Solution {
private:
    void dfs(vector<vector<int>> &graph,int src,vector<bool> &vis) {
        vis[src] = true;

        for(int j = 0 ; j < graph.size() ; j++) {
            if(graph[src][j] && !vis[j]) {
                dfs(graph,j,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n,false);
        int connectedComponents = 0;

        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                connectedComponents += 1;
                dfs(isConnected,i,vis);
            }
        }
        return connectedComponents;
    }
};