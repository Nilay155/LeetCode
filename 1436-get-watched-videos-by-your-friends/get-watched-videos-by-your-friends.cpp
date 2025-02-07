class Solution {
private:
    static bool cmp(string &a,string &b) {
        if(a < b) return true;
        else return false;
    }
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();

        // Graph-Creation
        vector<vector<int>> adjMatrix(n,vector<int>(n,0));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < friends[i].size() ; j++) {
                adjMatrix[i][friends[i][j]] = 1;
                // adjMatrix[friends[i][j]][i] = 1;
            }
        }

        unordered_map<string,int> mpp;
        vector<int> vis(n,0);

        int lvl = 0;
        queue<int> q;
        q.push(id);
        vis[id] = 1;
        while(!q.empty()) {
            int sz = q.size();

            if(lvl == level) {
                for(int i = 0 ; i < sz ; i++) {
                    int node = q.front(); q.pop();
                    for(int j = 0 ; j < watchedVideos[node].size() ; j++) {
                        mpp[watchedVideos[node][j]]++;
                    }
                }
            }
            if(q.empty()) break;
            for(int i = 0 ; i < sz ; i++) {
                int node = q.front(); q.pop();

                for(int j = 0 ; j < n ; j++) {

                    if(adjMatrix[node][j] && !vis[j]) {
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
            lvl += 1;
        }

        map<int,vector<string>> map;
        for(auto& it : mpp) {
            map[it.second].push_back(it.first);
        }

        for(auto& it : map) {
            sort(it.second.begin(),it.second.end(),cmp);
        }
        vector<string> res;
        for(auto& it : map) {
            cout << it.first << endl;
            for(int j = 0 ; j < it.second.size(); j++) {
                cout << it.second[j] << "  ";
                res.push_back(it.second[j]);
            }cout << endl << endl;
        }
        // reverse(res.begin(),res.end());
        return res;
    }
};