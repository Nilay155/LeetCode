class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        sort(points.begin(),points.end(),[&](vector<int> &A,vector<int> &B) {
            if(A[0] == B[0])
                return A[1] > B[1];
            return A[0] < B[0];
        });

        for(int i = 0 ; i < n ; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int y_max = INT_MIN;
            for(int j = i + 1 ; j < n ; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if(y2 > y_max) {
                    if(x1 == x2 && y1 > y2)
                        count += 1, y_max = max(y_max,y2);
                    else if(y1 >= y2)
                        count += 1, y_max = max(y_max,y2);
                    
                }
            }
        }
        return count;
    }
};