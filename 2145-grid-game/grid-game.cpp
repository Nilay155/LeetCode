class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long topSum = 0, bottomSum = 0;
        for(int i = 0 ; i < m ; i++) topSum += grid[0][i];

        long long ans = LLONG_MAX;
        for(int i = 0 ; i < m ; i++) {
            topSum -= grid[0][i];

            ans = min(ans,max(topSum,bottomSum));
            bottomSum += grid[1][i];
        }
        return ans;
    }
};