class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles, empty = 0;
        int ans = 0;

        while(full) {

            if(full >= numExchange) {
                ans += numExchange;
                full -= numExchange - 1;
                numExchange += 1;
            } else {
                ans += full;
                full = 0;
            }
        }
        return ans;
    }
};