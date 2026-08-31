class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n, 0);
        vector<int> parent(n, -1);
        vector<int> subtree(n, 1);

        // -------------------------------------------------
        // DFS from 0
        // dist[i] = distance of i from 0
        // subtree[i] = number of nodes below i
        // -------------------------------------------------
        function<void(int, int)> dfs = [&](int node, int par) {

            parent[node] = par;

            for (int next : adj[node]) {

                if (next == par)
                    continue;

                dist[next] = dist[node] + 1;

                dfs(next, node);

                subtree[node] += subtree[next];
            }
        };

        dfs(0, -1);

        // -------------------------------------------------
        // Initial sum of distances from node 0
        // -------------------------------------------------
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += dist[i];
        }

        // -------------------------------------------------
        // Reroot
        //
        // When moving:
        //
        //       node
        //         |
        //       child
        //
        // subtree[child] nodes become 1 closer
        //
        // n - subtree[child] nodes become 1 farther
        //
        // newSum =
        //      oldSum
        //      - subtree[child]
        //      + (n - subtree[child])
        //
        //      = oldSum + n - 2 * subtree[child]
        // -------------------------------------------------
        vector<int> ans(n);

        ans[0] = sum;

        function<void(int, int)> reroot =
            [&](int node, int par) {

                for (int next : adj[node]) {

                    if (next == par)
                        continue;

                    ans[next] =
                        ans[node]
                        + n
                        - 2 * subtree[next];

                    reroot(next, node);
                }
            };

        reroot(0, -1);

        return ans;
    }
   
};