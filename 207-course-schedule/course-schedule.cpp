class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for(int i = 0 ; i < prerequisites.size() ; i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        unordered_map<int,int> inDegree;

        for(int i = 0 ; i < numCourses ; i++) {
            for(int node : adjList[i]) {
                inDegree[node]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for(int child : adjList[node]) {
                inDegree[child]--;
                if(inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        
        if(cnt == numCourses) return true;
        else return false;
    }
};