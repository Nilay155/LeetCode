class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b) {

        double k1 = a[0]/a[1];
        double k2 = b[0]/b[1];

        return k1 < k2;
    }
    double increment(int pass,int total) {

        double res = (double(pass+1)/double(total+1)) - (double(pass)/double(total));
        return res;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double ans = 0;

        priority_queue<pair<double,int>> pq;
        for(int i = 0 ; i < n ; i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            pq.push({increment(pass,total),i});
        }

        for(int i = 0 ; i < extraStudents; i++) {
            
            auto p = pq.top();
            pq.pop();
            

            int k = p.second;
            
            classes[k][0] = classes[k][0] + 1;
            classes[k][1] = classes[k][1] + 1;
            pq.push({increment(classes[k][0],classes[k][1]),k});
        }

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int k = p.second;
            ans += double(classes[k][0])/double(classes[k][1]);
        }
        return (ans/n);
    }
};