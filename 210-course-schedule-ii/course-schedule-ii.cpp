class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // [ai,bi] -> bi is a prerequisite for ai
        // return ordering of courses to finish all courses
        // if impossible return empty array

        // Using DFS The Problem can be solved

        vector<vector<int>> adjList(numCourses);

        for(auto& it : prerequisites) {
            adjList[it[1]].push_back(it[0]);
        }

        unordered_map<int,int> inDegree;
        for(int i = 0 ; i < numCourses ; i++) {
            for(int child : adjList[i]) {
                inDegree[child]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()) {

            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int child : adjList[node]) {
                inDegree[child]--;
                if(inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        if(ans.size() == numCourses) return ans;
        else return {};
    }
};