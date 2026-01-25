typedef long long ll;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll maxSquare = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(i != j) {
                    int minx = max(bottomLeft[i][0],bottomLeft[j][0]);
                    int maxx = min(topRight[i][0],topRight[j][0]);

                    int miny = max(bottomLeft[i][1],bottomLeft[j][1]);
                    int maxy = min(topRight[i][1],topRight[j][1]);

                    if(miny > maxy || minx > maxx) continue;
                    int length = maxx - minx;
                    int breadth = maxy - miny;

                    ll area = 1LL * min(length,breadth) * min(length,breadth);
                    maxSquare = max(maxSquare,area);
                }
            }
        }
        return maxSquare;
    }
};