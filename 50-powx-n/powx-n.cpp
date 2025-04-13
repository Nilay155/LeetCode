class Solution {
private:
    double power(double x,long long n) {
        double ret = 1.0;
        long long  exp = n;
        double mul = x;
        while(exp > 0) {
            if(exp%2 == 1) {
                ret = ret * mul;
            }
            mul = mul*mul;
            exp /= 2;
        }
        return ret;
    }
public:
    double myPow(double x, int n) {
        long long temp = n;
        if(n < 0) return 1.00/power(x,-temp);
        else return power(x,n);
    }
};