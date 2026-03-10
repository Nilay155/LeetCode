class Solution {
private:
    double euclideanDistance(int x1,int y1,int x2,int y2) {

        double x = x1 - x2, y = y1 - y2;
        double distance = sqrt(x*x + y*y);
        return distance;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double,int>> pq;

        for(int i = 0 ; i < k ; i++) {
            pq.push({euclideanDistance(points[i][0],points[i][1],0,0),i});
        }

        for(int i = k ; i < n ; i++) {
            double ed = euclideanDistance(points[i][0],points[i][1],0,0);
            auto [top,index] = pq.top(); pq.pop();

            if(ed < top) {
                pq.push({ed,i});
            } else {
                pq.push({top,index});
            }
        }
        vector<vector<int>> nums;
        while(!pq.empty()) {
            auto [ed,index] = pq.top(); pq.pop();
            nums.push_back({points[index][0],points[index][1]});
        }
        return nums;
    }
};