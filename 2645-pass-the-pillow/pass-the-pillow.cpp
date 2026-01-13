class Solution {
public:
    int passThePillow(int n, int k) {
        int r = 0;
        r += (k) / (n-1);
        int left = k % (n-1);

        if(r % 2 == 1) {
            return n  - left;
        }  else {
            return left + 1;
        }
    }
};