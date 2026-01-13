class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),[&](const vector<int> &a,const vector<int> &b) {
            return a[0] < b[0];
        });

        int maxWidth = 0;
        int prev = points[0][0];

        for(int i = 1 ; i < n ; i++) {
            int curr = points[i][0];
            maxWidth = max(maxWidth,curr - prev);
            prev = curr;
        }
        return maxWidth;
    }
};