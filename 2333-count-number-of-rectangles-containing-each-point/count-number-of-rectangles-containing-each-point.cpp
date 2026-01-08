class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles,
                                vector<vector<int>>& points) {

        int n = rectangles.size(), m = points.size();

        // Sort rectangles by length descending
        sort(rectangles.begin(), rectangles.end(),
             [](auto &a, auto &b) {
                 return a[0] > b[0];
             });

        // points: x, y, index
        vector<vector<int>> p;
        for (int i = 0; i < m; i++) {
            p.push_back({points[i][0], points[i][1], i});
        }

        // Sort points by x descending
        sort(p.begin(), p.end(),
             [](auto &a, auto &b) {
                 return a[0] > b[0];
             });

        vector<int> freq(101, 0);  // hi <= 100
        vector<int> ans(m);

        int ridx = 0;

        for (auto &pt : p) {
            int x = pt[0], y = pt[1], idx = pt[2];

            // Add all rectangles with li >= x
            while (ridx < n && rectangles[ridx][0] >= x) {
                freq[rectangles[ridx][1]]++;
                ridx++;
            }

            // Count rectangles with hi >= y
            int count = 0;
            for (int h = y; h <= 100; h++) {
                count += freq[h];
            }

            ans[idx] = count;
        }

        return ans;
    }
};
