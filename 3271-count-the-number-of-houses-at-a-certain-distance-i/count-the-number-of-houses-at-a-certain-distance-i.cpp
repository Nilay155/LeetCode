class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adjList(n + 1);
        for(int i = 1 ; i < n ; i++) {
            adjList[i].push_back(i + 1);
            adjList[i + 1].push_back(i);
        }
        if(x != y && x != y + 1 && x + 1 != y)
            adjList[x].push_back(y), adjList[y].push_back(x);
        
        vector<vector<int>> distances(n + 1,vector<int> (n + 1,0));
        vector<int> counts(n,0);
        for(int i = 1 ; i <= n ; i++) {
            // BFS
            queue<int> q;
            q.push(i);
            vector<bool> vis(n + 1,false);
            vis[i] = true;
            int moves = 0;

            while(!q.empty()) {
                int sz = q.size();
                for(int j = 0 ; j < sz ; j++) {
                    int node = q.front();
                    q.pop();
                    distances[i][node] = moves;
                    for(int nbr : adjList[node]) {
                        if(!vis[nbr]) {
                            vis[nbr] = true;
                            q.push(nbr);
                        }
                    }
                }
                moves += 1;
            }
            for(int j = 1 ; j <= n ; j++) {
                if(i == j) continue;
                counts[distances[i][j] - 1] += 1;
            }
        }
        return counts;
    }
};