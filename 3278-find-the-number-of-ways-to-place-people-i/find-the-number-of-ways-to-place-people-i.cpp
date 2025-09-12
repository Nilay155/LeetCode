class Solution {
private:
    bool isUpper(int x1,int y1,int x2,int y2) {
        if(x1 == x2) return true;
        else if((x2 < x1 && y1 <= y2)) return true;
        else return false;
    }
    bool checkPoints(vector<vector<int>> &points,int x1,int y1,int x2,int y2) {
        // verify if any other point exists in the rectangle or on the line
        int ubx = max(x1,x2), lbx = min(x1,x2);
        int uby = max(y1,y2), lby = min(y1,y2);

        for(int i = 0 ; i < points.size() ; i++) {

            int x = points[i][0], y = points[i][1];

            if(x == x1 && y == y1) continue;
            if(x == x2 && y == y2) continue;

            if((x <= ubx && x >= lbx) && (y <= uby && y >= lby)) return false;
        }
        return true;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        // 1. sorting to ensure left-side
        sort(points.begin(),points.end());

        // 2. checking for every point

        // O(n)
        for(int i = 0 ; i < n ; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            // checking the left-side points
            // O(n)
            for(int j = i-1 ; j >= 0 ; j--) {
                int x2 = points[j][0], y2 = points[j][1];
                // O(1)
                if(isUpper(x1,y1,x2,y2)) {
                    // O(n)
                    if(checkPoints(points,x1,y1,x2,y2)) {
                        ans += 1;
                    }
                }
            }
        }
        // T.C. -> O(n*n*n), S.C -> O(1)
        return ans;
    }
};