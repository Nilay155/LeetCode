class Solution {
public:
    bool isPowerOfTwo(int n) {
        int setBits = 0;
        if(n <= 0) return false;
        while(n) {
            setBits += n%2;
            n /= 2;
        }
        return setBits == 1;
    }
};