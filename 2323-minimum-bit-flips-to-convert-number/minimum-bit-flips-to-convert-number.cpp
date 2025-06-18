class Solution {
public:
    int minBitFlips(int start, int goal) {

        int flips = 0;
        while(goal || start) {
            int g = goal%2;
            int s = start%2;

            if(s != g) flips += 1;

            start /= 2;
            goal /= 2;
        }
        return flips;
    }
};