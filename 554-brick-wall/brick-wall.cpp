typedef long long ll;
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();

        unordered_map<ll,int> wallEndings;
        for(int i = 0 ; i < n ; i++) {
            int m = wall[i].size();
            ll sum = 0;
            for(int j = 0 ; j < m ; j++) {
                if(j == m - 1) continue;
                sum += wall[i][j];
                wallEndings[sum] += 1; 
            }
        }

        int ans = n;
        for(auto [v,wallEnding] : wallEndings) {
            ans = min(ans,n - wallEnding);
        }
        return ans;
    }
};