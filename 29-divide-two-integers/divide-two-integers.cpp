class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        int sign = ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) ? -1 : 1 ;

        long long a = labs(dividend), b = labs(divisor);
        long long res = 0;

        while(a >= b) {
            long long temp = b, cnt = 1;
            while(temp << 1 <= a) {
                temp <<= 1;
                cnt <<= 1;
            }
            a -= temp;
            res += cnt;
        }
        return sign*res;
    }
};