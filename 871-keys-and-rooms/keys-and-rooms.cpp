class Solution {
private:
    int sz = 0;
    void dfs(int src,vector<vector<int>> &adjList,vector<bool> &vis) {
        vis[src] = true;
        sz += 1;

        for(int nbr : adjList[src])
            if(!vis[nbr])
                dfs(nbr,adjList,vis);
        return;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adjList(n);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < rooms[i].size() ; j++) {
                adjList[i].push_back(rooms[i][j]);
            }
        }

        vector<bool> vis(n,false);
        dfs(0,adjList,vis);

        return sz == n ? true : false;
    }
};