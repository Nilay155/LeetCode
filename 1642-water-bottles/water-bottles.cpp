class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans = 0, extra = 0;
        while(numBottles) {
            ans += numBottles;
            int emptyBottles = numBottles + extra;
            int refill = emptyBottles / numExchange;
            extra = emptyBottles % numExchange;
            numBottles = refill;
        } 
        return ans;
    }
};