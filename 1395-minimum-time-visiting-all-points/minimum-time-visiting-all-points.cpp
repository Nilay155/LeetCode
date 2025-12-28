class Solution {
private:
    int manhattanDistance(int x,int y) {
        return abs(x-y);
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            int u = manhattanDistance(points[i][0],points[i+1][0]);
            int v = manhattanDistance(points[i][1],points[i+1][1]);

            int mini = min(u,v);
            u -= mini, v -= mini;
            ans += (mini + v + u);
        }
        return ans;
    }
};