class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        int u = edges[0][0], v = edges[0][1];

        for(int i = 1 ; i < n ; i++) {
            int nu = edges[i][0], nv = edges[i][1];

            if(nu == u || nv == u) return u;
            if(nu == v || nv == v) return v;
        }
        return -1;
    }
};