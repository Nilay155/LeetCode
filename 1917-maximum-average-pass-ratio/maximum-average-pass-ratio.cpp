class Solution {
private:
    double calculateGainRatio(int pass,int total) {
        double oldRatio = (double)pass/(double)total;
        double newRatio = (double)(pass + 1)/(double)(total + 1);

        double gain = newRatio - oldRatio;
        return gain;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>> ratioGains;
        for(int i = 0 ; i < n ; i++) {
            ratioGains.push({calculateGainRatio(classes[i][0],classes[i][1]) , i});
        }

        while(extraStudents--) {
            auto [gain,index] = ratioGains.top(); ratioGains.pop();
            classes[index][0] += 1;
            classes[index][1] += 1;
            ratioGains.push({calculateGainRatio(classes[index][0],classes[index][1]) , index});
        }

        double ans = 0.00;
        for(int i = 0 ; i < n ; i++) {
            double ratio = (double) classes[i][0] / (double) classes[i][1];
            ans += ratio;
        }
        return ans/(double)n;
    }
};