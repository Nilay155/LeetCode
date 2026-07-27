class Solution {
private:
    int f(vector<int> &cost,int s) {
        int n = cost.size();
        int prevOne = cost[s + 1] + min(cost[0], s == 1 ? cost[1] : INT_MAX), prevTwo = cost[s];
        for(int i = s + 2 ; i < n ; i++) {
            int currCost = cost[i] + min(prevOne,prevTwo);
            prevTwo = prevOne;
            prevOne = currCost;
        }
        return min(prevOne,prevTwo);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // target_index == n
        if(n == 1) return cost[0];
        if(n == 2) return min(cost[0],cost[1]);
        return min(f(cost,0),f(cost,1));  
    }
};