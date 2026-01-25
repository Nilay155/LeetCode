class Solution {
private:
    vector<int> topoOrder(unordered_map<int,vector<int>> &graph,int k) {
        unordered_map<int,int> inDegree;
        for(int i = 1 ; i <= k ; i++) inDegree[i] = 0;
        queue<int> q;
        for(auto [parent,adjList] : graph) {
            for(int child : adjList) {
                inDegree[child] += 1;
            }
        }
        for(auto [node,count] : inDegree) {
            if(count == 0)
                q.push(node);
        }

        vector<int> topo;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(int child : graph[node]) {
                inDegree[child] -= 1;
                if(inDegree[child] == 0) 
                    q.push(child);
            }
        }
        // cout << topo.size() << "    " << n << "\n";
        if(topo.size() == k) return topo;
        else return {};
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k,vector<int>(k,0));
        unordered_map<int,vector<int>> g1,g2;
        for(auto row : rowConditions) {
            g1[row[0]].push_back(row[1]);
        }
        for(auto col : colConditions) {
            g2[col[0]].push_back(col[1]);
        }

        vector<int> row = topoOrder(g1,k);
        vector<int> col = topoOrder(g2,k);
        if(row.empty() || col.empty()) return {};

        int i = 0, x = row.size();
        int j = 0, y = col.size();
        unordered_map<int,pair<int,int>> rowCol;
        for(int l = 0 ; l < k ; l++) {
            rowCol[row[l]].first = l;
            rowCol[col[l]].second = l;
        }
        int u = 0, v = 0;
        for(int i = 1 ; i <= k ; i++) {
            auto [r,c] = rowCol[i];
            ans[r][c] = i;
        }
        return ans;
    }
};