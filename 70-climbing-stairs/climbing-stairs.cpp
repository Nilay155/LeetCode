class Solution {
public:
    int climbStairs(int n) {
        
        // vector<int> dp(n + 1,0);
        int prevOne = 1, prevTwo = 1;
        for(int i = 2 ; i <= n ; i++) {
            int curr = prevOne + prevTwo;
            prevTwo = prevOne;
            prevOne = curr;
        }
        return prevOne;
    }
};