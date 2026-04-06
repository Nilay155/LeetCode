class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> inDegree(n + 2,0);

        for(auto edge : edges) inDegree[edge[0]] += 1, inDegree[edge[1]] += 1;
        for(int node = 1 ; node <= n + 1 ; node++) {
            if(inDegree[node] == n)
                return node;
        }
        return -1;
    }
};