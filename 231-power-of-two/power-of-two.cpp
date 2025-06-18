class Solution {
public:
    bool isPowerOfTwo(int n) {

        int count = 0;

        while(n) {
            int bit = n%2;
            if(bit == 1) count += 1;
            n /= 2;
        }
        return count == 1;
    }
};