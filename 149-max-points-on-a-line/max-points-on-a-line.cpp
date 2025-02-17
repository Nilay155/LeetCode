class Solution {
private:
    double computeSlope(int x1,int y1,int x2,int y2) {
        if(x2-x1 == 0) return 1000000000.00;
        else return double(y2-y1)/double(x2-x1);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        unordered_map<int,unordered_map<double,int>> mpp;

        for(int i = 0 ; i < n ; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for(int j = i+1 ; j < n ; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                double m = computeSlope(x1,y1,x2,y2);
                mpp[j][m] = 1 + mpp[i][m];
            }
        }

        int ans = 0;
        for(auto& temp : mpp) {
            for(auto& it : temp.second) {
                ans = max(ans,it.second);
            }
        }
        return ++ans;
    }
};