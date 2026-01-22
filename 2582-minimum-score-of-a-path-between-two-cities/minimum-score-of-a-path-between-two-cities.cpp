class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto road : roads) {
            adjList[road[0]].push_back({road[1],road[2]});
            adjList[road[1]].push_back({road[0],road[2]});
        }

        vector<bool> vis(n+1,false);
        queue<int> q;
        q.push(1), vis[1] = true;
        bool flag = false;
        int mini = INT_MAX;

        while(!q.empty()) {
            int node = q.front(); q.pop();
            if(node == n) flag = true;

            for(auto [nbr,distance] : adjList[node]) {
                mini = min(mini,distance);
                if(!vis[nbr]) {
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return mini;
    }
};