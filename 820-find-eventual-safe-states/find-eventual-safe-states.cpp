class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<vector<int>> adjList(n);
        for(int i = 0 ; i < n ; i++) {
            for(int node : graph[i]) {
                adjList[node].push_back(i);
            }
        }
        unordered_map<int,int> outDegree;

        for(int i = 0 ; i < n ; i++) {
            outDegree[i] = graph[i].size();
        }

        queue<int> q;
        for(int i = 0 ; i < n ; i++) {
            if(outDegree[i] == 0) {
                q.push(i);
            }
        }
        cout << q.size() << endl;
        vector<int> ans;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(int child : adjList[top]) {
                outDegree[child]--;
                if(outDegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};