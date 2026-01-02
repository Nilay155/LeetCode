class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double sum = 0;
        double k = n;

        int currTime = 0;

        for(int i = 0 ; i < n ; i++) {
            int a = customers[i][0], p = customers[i][1];
            currTime = max(currTime,a);
            int waitingTime = currTime + p - a;
            sum += (double) waitingTime;
            currTime += p;
        }
        return sum/k;
    }
};