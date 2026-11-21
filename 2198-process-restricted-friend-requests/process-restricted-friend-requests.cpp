class DSU {
private:
    vector<int> parent,size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);

        for(int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
    }

    void unionBySize(int u,int v) {
        int parU = findPar(u);
        int parV = findPar(v);
        
        if(parU == parV) 
            return ;

        int sizeU = size[parU];
        int sizeV = size[parV];

        if(sizeU >= sizeV) {
            size[parU] += size[parV];
            parent[parV] = parU;
        } else {
            size[parV] += size[parU];
            parent[parU] = parV;
        }
        return ;
    }
    int findPar(int p) {
        if(p == parent[p])
            return p;
        
        return parent[p] = findPar(parent[p]);
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU groups(n);
        vector<vector<bool>> links(n,vector<bool>(n,false));
        int r1 = restrictions.size(), r2 = requests.size();
        for(int i = 0 ; i < r1 ; i++) {
            int u = restrictions[i][0],
                v = restrictions[i][1];

            links[u][v] = links[v][u] = true;
        }

        vector<bool> ans(r2,false);
        for(int i = 0 ; i < r2 ; i++) {
            int u = requests[i][0],
                v = requests[i][1];

            int parU = groups.findPar(u),
                parV = groups.findPar(v);
            
            if(links[parU][parV] || links[parV][parU])
                continue;
            
            ans[i] = true;
            groups.unionBySize(u,v);
            int par = groups.findPar(u);

            for(int j = 0 ; j < n ; j++) {
                if(links[j][parU] || links[parU][j] || links[parV][j] || links[j][parV])
                    links[par][j] = links[j][par] = true;
            }
        }
        return ans;
    }
};