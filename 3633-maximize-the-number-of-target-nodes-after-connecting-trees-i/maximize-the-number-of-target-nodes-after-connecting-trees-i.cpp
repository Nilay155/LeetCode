class Solution {
private:
    void bfs(vector<vector<int>> &tree,int src,int k,vector<int> &td) {
        int n = tree.size();
        queue<pair<int,int>> q;
        vector<bool> vis(n);

        q.push({src,0});
        vis[src] = true;

        while(!q.empty()) {
            auto [node,distance] = q.front(); q.pop();
            if(distance <= k) td[src] += 1;
            else continue;
            for(int nbr : tree[node]) {
                if(!vis[nbr]) {
                    q.push({nbr,distance + 1});
                    vis[nbr] = true;
                }
            }
        }
        return ;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> tree1(n+1),tree2(m+1);

        for(auto edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }    
        for(auto edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        vector<int> td1(n+1), td2(m+1);

        for(int i = 0 ; i <= n ; i++) bfs(tree1,i,k,td1);
        for(int i = 0 ; i <= m ; i++) bfs(tree2,i,k-1,td2);

        int maxi = INT_MIN;
        for(int ele : td2) maxi = max(maxi,ele);

        vector<int> result(n+1);
        for(int i = 0 ; i <= n ; i++) {
            result[i] = td1[i] + maxi;
        }
        return result;
    }
};