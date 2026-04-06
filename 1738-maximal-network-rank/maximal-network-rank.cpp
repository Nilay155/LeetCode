class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> inDegree(n,0);
        for(auto road : roads) inDegree[road[0]] += 1, inDegree[road[1]] += 1;

        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(auto road : roads) vis[road[0]][road[1]] = vis[road[1]][road[0]] = true;

        vector<vector<int>> pairs;
        for(int i = 0 ; i < n ; i++) pairs.push_back({inDegree[i],i});
        sort(pairs.begin(),pairs.end());
        int maxIndegree = pairs[n - 1][0], maxRank = 0;
 
        for(int i = n - 1 ; i >= 1 && pairs[i][0] == maxIndegree ; i--) {

            for(int j = i - 1 ; j >= 0 ; j--) {
                int extra = 0;
                if(vis[pairs[i][1]][pairs[j][1]] || vis[pairs[j][1]][pairs[i][1]]) 
                    extra += 1;
                maxRank = max(maxRank,maxIndegree + pairs[j][0] - extra);
            }
        }
        return maxRank;
    }
};