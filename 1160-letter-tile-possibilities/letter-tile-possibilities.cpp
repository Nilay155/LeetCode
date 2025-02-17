class Solution {
private:
    int solve(string &tiles,vector<bool> &vis,string &temp,int &n,vector<int> &count) {
        
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++) {

            if(count[i]) {
                count[i]--;
                ans += 1 + solve(tiles,vis,temp,n,count);
                count[i]++;
            }
        }
        return ans;
    }
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> vis(n,false);
        vector<int> count(26,0);
        string temp;
        for(int i = 0 ; i < n ; i++) count[tiles[i]-'A']++;
        return solve(tiles,vis,temp,n,count);
    }
};