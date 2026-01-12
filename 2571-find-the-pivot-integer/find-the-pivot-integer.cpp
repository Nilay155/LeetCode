class Solution {
public:
    int pivotInteger(int n) {
        int ans = -1;
        for(int p = 1 ; p <= n ; p++) {

            int L = p * (p + 1) / 2;
            int R = n * (n + 1) / 2;
            R = R - L + p;

            if(L == R) {
                ans = p;
                break;
            }
        }
        return ans;
    }
};