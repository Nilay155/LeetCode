typedef long long ll;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll side = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                
                int minx = max(bottomLeft[i][0],bottomLeft[j][0]);
                int maxx = min(topRight[i][0],topRight[j][0]);

                int miny = max(bottomLeft[i][1],bottomLeft[j][1]);
                int maxy = min(topRight[i][1],topRight[j][1]);

                if(miny > maxy || minx > maxx) continue;
                ll length = maxx - minx;
                ll breadth = maxy - miny;
                side = max(side,min(length,breadth));
            }
        }
        return 1LL * side * side;
    }
};