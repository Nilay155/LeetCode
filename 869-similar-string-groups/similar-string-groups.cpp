class Solution {
public:
    int numSimilarGroups(vector<string>& arr) {
        
        int n = arr.size(), groups = 0;
        vector<string> strs;
        unordered_map<string,int> mark;
        for(int i = 0 ; i < n ; i++) {
            if(mark.find(arr[i]) == mark.end()) {
                strs.push_back(arr[i]);
                mark[arr[i]] = i;
            }
        }
        n = strs.size();
        for(int i = 0 ; i < n ; i++) mark[strs[i]] = i;
        vector<bool> vis(n,false);
        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                queue<string> q;
                q.push(strs[i]);
                vis[i] = true;
                while(!q.empty()) {
                    int sz = q.size();
                    for(int k = 0 ; k < sz ; k++) {
                        string s = q.front(); q.pop();
                        int m = s.length();
                        for(int u = 0 ; u < m ; u++) {
                            for(int v = 0 ; v < m ; v++) {

                                swap(s[u],s[v]);
                                if(mark.find(s) != mark.end() && !vis[mark[s]]) {
                                    q.push(s);
                                    vis[mark[s]] = true;
                                }
                                swap(s[u],s[v]);
                            }
                        }
                    }
                }
                groups += 1;
            }
        }
        return groups;
    }
};