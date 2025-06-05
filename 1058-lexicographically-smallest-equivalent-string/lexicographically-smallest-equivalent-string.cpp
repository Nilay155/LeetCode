class Solution {
private:
    void dfs(int src,unordered_map<char,vector<char>> &graph,int &mini,vector<bool> &vis) {
        vis[src] = true;

        for(char child : graph[('a' + src)]) {
            if(!vis[(child-'a')]) {
                mini = min(mini,child-'a');
                dfs(child-'a',graph,mini,vis);
            }
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length(), m = baseStr.length();

        // Graph Creation
        unordered_map<char,vector<char>> mpp;
        for(int i = 0 ; i < n ; i++) {
            mpp[s1[i]].push_back(s2[i]); 
            mpp[s2[i]].push_back(s1[i]);
        }
        string ans;
        for(int i = 0 ; i < m ; i++) {
            vector<bool> vis(26,false);
            int mini = baseStr[i]-'a';
            dfs(mini,mpp,mini,vis);
            char ch = 'a' + mini;  // ch = 'e' (because 'a' + 4 = 'e')
            ans.push_back(ch);
        }
        return ans;
    }
};