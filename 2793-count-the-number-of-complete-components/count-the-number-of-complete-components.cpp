class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) 
                swap(rootA, rootB);
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU ds(n);

        for(auto edge : edges) {
            ds.unite(edge[0],edge[1]);
        }

        vector<int> count(n,0);
        for(auto edge : edges) {
            int ulpU = ds.find(edge[0]);
            int ulpV = ds.find(edge[1]);

            if(ulpU == ulpV) {
                count[ulpU] += 1;
            }
        }

        unordered_set<int> st;
        for(int par : ds.parent) st.insert(par);
        int ans = 0;
        for(int node : st) {
            int temp = ds.size[node];
            int val = (temp*(temp-1))/2;
            
            if(count[node] == val) ans++;
        }
        return ans;
    }
};