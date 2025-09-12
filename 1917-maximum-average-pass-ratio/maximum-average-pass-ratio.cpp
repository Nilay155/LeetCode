class Solution {
private:
    double classRatio(int pass,int total) {
        return double(pass+1)/double(total+1) - double(pass)/double(total);
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double,int>> pq;


        for(int i = 0 ; i < n ; i++) {
            double ratio = classRatio(classes[i][0],classes[i][1]);
            pq.push({ratio,i});
        }

        while(extraStudents--) {
            auto [ratio,i] = pq.top(); pq.pop();
            classes[i][0] += 1;
            classes[i][1] += 1;
            double newRatio = classRatio(classes[i][0],classes[i][1]);
            pq.push({newRatio,i});
        }

        double ans = 0.0;
        for(int i = 0 ; i < n ; i++) {
            double ratio = double(classes[i][0])/double(classes[i][1]);
            ans += ratio;
        }
        return double(ans) / double(n);
    }
};