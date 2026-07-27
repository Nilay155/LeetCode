class Solution {
private:
    double bfs(string &source,string &destination,unordered_map<string,vector<pair<string,double>>> &adjList) {

        queue<pair<string,double>> q;
        q.push({source,1.00});
        unordered_map<string,bool> vis;
        vis[source] = true;

        while(!q.empty()) {
            auto [front,value] = q.front(); q.pop();

            if(front == destination)
                return value;
            
            for(auto [nbr,cost] : adjList[front]) {
                if(!vis[nbr])  {
                    vis[nbr] = true;
                    q.push({nbr,cost * value});
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>> adjList;
        unordered_map<string,bool> vis;
        int n = equations.size();
        for(int i = 0 ; i < n ; i++) {
            adjList[equations[i][0]].push_back({equations[i][1],values[i]});
            adjList[equations[i][1]].push_back({equations[i][0],1.00/values[i]});
            vis[equations[i][0]] = vis[equations[i][1]] = true;
        }

        int m = queries.size();
        vector<double> ans(m,-1.00);
        for(int i = 0 ; i < m ; i++) {

            string c = queries[i][0];
            string d = queries[i][1];
            if(!vis.count(d) || !vis.count(c))
                continue;
            ans[i] = bfs(c,d,adjList);
            if(ans[i] == -1.00)
                ans[i] = 1.00 / (bfs(d,c,adjList));
        }
        return ans;
    }
};