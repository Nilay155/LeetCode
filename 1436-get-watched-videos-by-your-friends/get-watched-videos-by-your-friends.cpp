class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        vector<vector<int>> adjList(n);

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < (int) friends[i].size() ; j++) {
                adjList[i].push_back(friends[i][j]);
            }
        }

        vector<bool> vis(n,false);
        vis[id] = true;

        queue<int> q;
        q.push(id);

        while(!q.empty() && level--) {
            int sz = q.size();
            while(sz--) {
                int f = q.front(); q.pop();
                for(int j = 0 ; j < (int) adjList[f].size() ; j++) {
                    if(!vis[adjList[f][j]]) {
                        vis[adjList[f][j]] = true;
                        q.push(adjList[f][j]);
                    }
                }
            }
        }

        unordered_map<string,int> counts;
        while(!q.empty()) {
            int f = q.front(); q.pop();
            for(int j = 0 ; j < (int) watchedVideos[f].size() ; j++) {
                counts[watchedVideos[f][j]] += 1;
            }
        }
        vector<pair<int,string>> arr;
        for(auto [str,cnt] : counts) {
            arr.push_back({cnt,str});
        }
        sort(arr.begin(),arr.end(),[&](pair<int,string> &A,pair<int,string> &B) {
            if(A.first == B.first)
                return A.second < B.second;
            return A.first < B.first;
        });
        vector<string> ans;
        for(int i = 0 ; i < (int) arr.size() ; i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};