class Solution {
public:
    int numberOfChild(int n, int k) {
        int r = 0;
        r += (k) / (n-1);
        int left = k % (n-1);

        if(r % 2 == 1) {
            return n - 1 - left;
        }  else {
            return 0 + left;
        }
    }
};