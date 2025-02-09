class Solution {
public:
    vector<int> dfs(vector<vector<int>> &adjList,int src,vector<bool> &vis) {
        vis[src] = true;

        int cnt = 0;
        int nodes = 1;

        for(int node : adjList[src]) {
            cnt += 1;
            if(!vis[node]) {
               auto p = dfs(adjList,node,vis);
               cnt += p[0];
               nodes += p[1]; 
            }
        }
        return {cnt,nodes};
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();

        vector<vector<int>> adjList(n);
        for(int i = 0 ; i < m ; i++) {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> vis(n,false);
        int extraCables = 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                auto p = dfs(adjList,i,vis);
                // cout << p[0] << " : " << p[1] << endl;
                int cablesNeeded = p[1]-1;
                extraCables += (p[0])/2 - cablesNeeded;
                count += 1;
            }
        }
        // cout << count << endl;
        if(count-1 <= extraCables) return count-1;
        else return -1;


    }
};