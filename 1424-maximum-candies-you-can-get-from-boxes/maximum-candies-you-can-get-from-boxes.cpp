class Solution {
private:
    void dfs(int src,vector<bool> &vis,vector<vector<int>> &containedBoxes,vector<int> &status,vector<vector<int>> &keys) {
        vis[src] = true;
        for(int key : keys[src]) {
            if(key == src) continue;
            status[key] = 1;
        }

        for(int child : containedBoxes[src]) {
            if(!vis[child]) {
                dfs(child,vis,containedBoxes,status,keys);
            }
        }
    }
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        int m = initialBoxes.size();

        unordered_map<int,vector<int>> graph;
        for(int i = 0 ; i < m ; i++) {
            int box = initialBoxes[i];
            for(int j = 0 ; j < containedBoxes[box].size() ; j++) {
                graph[box].push_back(containedBoxes[box][j]);
            }
        }
        vector<bool> vis(n,false);
        for(int i = 0 ; i < m ; i++) {
            int box = initialBoxes[i];
            if(!vis[box]) {
                dfs(box,vis,containedBoxes,status,keys);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(status[i] && vis[i]) {
                ans += candies[i];
            }
        }
        return ans;
    }
};