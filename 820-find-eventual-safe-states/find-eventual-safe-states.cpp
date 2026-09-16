class Solution {
private:
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n,0);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < (int) graph[i].size() ; j++) {
                adjList[graph[i][j]].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(int nbr : adjList[node]) {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};