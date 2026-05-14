// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
//     }
// };
class Solution {
public:

    vector<vector<int>> graph;

    pair<int, int> bfs(int start, vector<int>& parent) {

        int n = graph.size();

        vector<int> dist(n, -1);

        queue<int> q;

        q.push(start);

        dist[start] = 0;

        int farthestNode = start;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            farthestNode = u;

            for (int v : graph[u]) {

                if (dist[v] == -1) {

                    dist[v] = dist[u] + 1;

                    parent[v] = u;

                    q.push(v);
                }
            }
        }

        return {farthestNode, dist[farthestNode]};
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        graph.resize(n);

        // Build graph
        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> parent1(n, -1);

        // First BFS -> find one end of diameter
        auto first = bfs(0, parent1);

        int A = first.first;

        vector<int> parent2(n, -1);

        // Second BFS -> actual diameter
        auto second = bfs(A, parent2);

        int B = second.first;

        // Reconstruct diameter path
        vector<int> path;

        int curr = B;

        while (curr != -1) {

            path.push_back(curr);

            curr = parent2[curr];
        }

        reverse(path.begin(), path.end());

        int sz = path.size();

        vector<int> ans;

        // One center
        if (sz % 2 == 1) {

            ans.push_back(path[sz / 2]);
        }
        // Two centers
        else {

            ans.push_back(path[sz / 2 - 1]);
            ans.push_back(path[sz / 2]);
        }

        return ans;
    }
};