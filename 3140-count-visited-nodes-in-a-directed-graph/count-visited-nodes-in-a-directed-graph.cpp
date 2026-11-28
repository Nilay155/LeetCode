class Solution {
private:
    void f(int node,vector<bool> &vis,vector<int> &ans,vector<int> &edges) {

        vis[node] = true;
        int next = edges[node];

        if(vis[next]) {
            if(ans[next] == -1) {
                // new cycle found
                int k = next, c = 0;
                while(edges[k] != next) {
                    c += 1;
                    k = edges[k];
                }
                c += 1;
                k = next;
                while(edges[k] != next) {
                    ans[k] = c;
                    k = edges[k];
                }
                ans[k] = c;
            } else {
                ans[node] = 1 + ans[next];
            }
        } else {
            f(next,vis,ans,edges);
            if(ans[node] == -1)
                ans[node] =  1 + ans[next];
        }
        return ;
    }
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        
        vector<bool> vis(n,false);
        vector<int> ans(n,-1);
        
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                f(i,vis,ans,edges);
            }
        }
        return ans; 

    }
};