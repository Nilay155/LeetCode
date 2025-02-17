class Solution {
private:
    unordered_set<string> s;
    void solve(string &tiles,vector<bool> &vis,string temp,int &n) {

        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                vis[i] = true;
                s.insert(temp+tiles[i]);
                solve(tiles,vis,temp+tiles[i],n);
                vis[i] = false;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> vis(n,false);
        solve(tiles,vis,"",n);
        for(auto& it : s) cout << it << "  " ;
        cout << endl;
        return s.size();
    }
};