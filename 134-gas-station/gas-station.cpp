class Solution {
private:
    pair<int,int> findValidStartingIndex(vector<int> &gas,vector<int> &cost) {
        int n = gas.size();

        int l = 0, r = 1, sum = gas[0];

        while(r < n) {
            if(sum - cost[r - 1] >= 0) {
                sum -= cost[r - 1];
                sum += gas[r];
            } else {
                while(l < r && sum - cost[r - 1] < 0) {
                    sum += cost[l];
                    sum -= gas[l];
                    l += 1;
                }
            }
            if(l == r) sum = gas[r];
            r += 1;
        }
        return {l,sum};
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        auto [r,rSum] = findValidStartingIndex(gas,cost);
        int lSum = -cost[n - 1], l = 0, mini = -cost[n - 1];
        while(l < r) {
            lSum += gas[l];
            lSum -= cost[l];
            mini = min(mini,lSum);
            l += 1;
        }

        while(r < n) {

            if(rSum >= abs(mini))
                return r;
            
            rSum -= gas[r];
            rSum += cost[r];
            

            lSum += gas[l];
            lSum -= cost[l];
            mini = min(mini,lSum);

            l += 1;
            r += 1;
        }
        return -1;
    }
};