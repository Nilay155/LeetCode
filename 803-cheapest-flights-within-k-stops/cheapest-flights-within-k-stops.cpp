class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        int e = f.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<e;i++){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({k,{src,0}});
        vector<int> vis(n,INT_MAX);
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int stops = curr.first;
            int node = curr.second.first;
            int cost = curr.second.second;
            for(auto p: adj[node]){
                if(stops==0){
                    if(p.first==dst and p.second + cost < vis[p.first]){
                        vis[p.first]=p.second+cost;
                        pq.push({stops-1,{p.first,vis[p.first]}});
                    }
                }else{
                    if(p.second + cost < vis[p.first]){
                        vis[p.first]=p.second+cost;
                        pq.push({stops-1,{p.first,vis[p.first]}});
                    }
                }
            }
        }
        if(vis[dst]==INT_MAX) return -1;
        return vis[dst];
        
    }
};