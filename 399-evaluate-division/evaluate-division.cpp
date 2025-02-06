class Solution {
private:
    double bfs(unordered_map<string,set<pair<string,double>>> &adjList,string &start,string &end) {
        queue<pair<string,double>> q;
        unordered_set<string> vis;

        q.push({start,1.0});
        vis.insert(start);

        while(!q.empty()) {

            string node = q.front().first;
            double value = q.front().second;
            q.pop();
            
            if(!adjList.count(node)) continue;
            if(node == end) return value;

            for(auto& p : adjList[node]) {
                
                if(!vis.count(p.first)) {
                    q.push({p.first,value*p.second});
                    vis.insert(p.first);
                }
            }
        }
        return -1.0;


    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        int m = queries.size();

        unordered_map<string,set<pair<string,double>>> adjList;

        for(int i = 0 ; i < n ; i++) {
            string ai = equations[i][0];
            string bi = equations[i][1];

            adjList[ai].insert({bi,values[i]});
            adjList[bi].insert({ai,1.0/values[i]});
        }
        vector<double> ans;
        for(int i = 0 ; i < m ; i++) {
            ans.push_back(bfs(adjList,queries[i][0],queries[i][1]));
        }
        return ans;
    }
};