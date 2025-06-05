class Solution {
private:
    void dfs(int src,unordered_map<char,vector<char>> &graph,vector<bool> &vis,vector<int> &minChar,int &mini) {
        vis[src] = true;
        minChar[src] = mini;

        for(char child : graph[('a' + src)]) {
            if(!vis[(child-'a')]) {
                dfs(child-'a',graph,vis,minChar,mini);
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

        vector<bool> vis(26,false);
        vector<int> minChar(26,26);
        for(int temp = 0 ; temp < 26 ; temp++) {
            if(!vis[temp]) {
                dfs(temp,mpp,vis,minChar,temp);
            }
        }
        string ans;
        for(int i = 0 ; i < m ; i++) {
            int mini = minChar[baseStr[i]-'a'];
            char ch = 'a' + mini;
            ans.push_back(ch);
        }
        return ans;
    }
};