typedef long long ll;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> inDegree(n,0);
        for(auto road : roads) {
            inDegree[road[0]] += 1;
            inDegree[road[1]] += 1;
        }
        vector<pair<int,int>> weights;
        for(int i = 0 ; i < n ; i++) {
            weights.push_back({inDegree[i],i});
        }
        sort(weights.begin(),weights.end());
        int k = n;
        for(int i = n-1 ; i >= 0 ; i--) {
            inDegree[weights[i].second] = i + 1;
        }
        ll maxValue = 0;
        for(auto road : roads) {
            int u = inDegree[road[0]], v = inDegree[road[1]];
            maxValue += u + v;
        }
        return maxValue;
    }
};