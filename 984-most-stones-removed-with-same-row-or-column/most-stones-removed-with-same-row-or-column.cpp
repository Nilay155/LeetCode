class Solution {
public:
    int dfs(vector<vector<int>> &adjList,vector<bool> &vis,int node) {

        vis[node] = true;
        int res = 0;
        for(int child : adjList[node]) {

            if(!vis[child]) {
                res += 1 + dfs(adjList,vis,child);
            }
        }
        return res;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adjList(n);

        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {            
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n,false);
        int ans = 0;

        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                ans += dfs(adjList,vis,i);
            }
        }
        return ans;
    }
};