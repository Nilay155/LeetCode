class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9 + 7;

        vector<vector<pair<long long,long long>>> adjList(n);
        for(auto edge : roads) {
            adjList[edge[0]*1LL].push_back({edge[1]*1LL,edge[2]*1LL});
            adjList[edge[1]*1LL].push_back({edge[0]*1LL,edge[2]*1LL});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;

        vector<long long> dist(n,1e18);
        vector<long long> ways(n,0);
        dist[0] = 0*1LL,ways[0] = 1*1LL;
        pq.push({0,0});
        
        while(!pq.empty()) {
            auto [w,u] = pq.top(); pq.pop();
   
            for(auto edge : adjList[u]) {
                auto [v,e] = edge;
                if(w + e == dist[v]) {
                    ways[v] = (ways[v] + ways[u])%MOD;
                } else if(w + e < dist[v]) {
                    dist[v] = w + e;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                }
            }
        }
        return ways[n-1];
    }
};