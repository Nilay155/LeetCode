class Solution {
private:
    bool check(vector<vector<int>> &points,int i,int j,int f) {
        int n = points.size();
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        
        if(f == j) {
            x1 = points[j][0], y1 = points[j][1];
            x2 = points[i][0], y2 = points[i][1];
        }

        for(int k = 0 ; k < n ; k++) {
            if(i == k || j == k) continue;
            int x3 = points[k][0], y3 = points[k][1];

            if((x3 >= x1 && x3 <= x2) && (y3 >= y2 && y3 <= y1))
                return false;
        }
        return true;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i + 1 ; j < n ; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                
                if(x1 <= x2 && y1 > y2) {
                    if(check(points,i,j,i))
                        count += 1;
                } else if(x1 < x2 && y1 >= y2) {
                    if(check(points,i,j,i))
                        count += 1;
                } else if(x2 <= x1 && y2 > y1) {
                    if(check(points,i,j,j))
                        count += 1;
                } else if(x2 < x1 && y2 >= y1) {
                    if(check(points,i,j,j))
                        count += 1;
                }
            }
        }
        return count;
    }
};