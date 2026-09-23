using ll = long long;
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        
        if(n == 1)
            return (ll) s;
        
        ll pos = (n & 1) ? n - 1 : n;
        ll k1 = pos / 2, k2 = k1 - 1;
        ll maxValue = s + k1 * (ll) m - k2;

        return maxValue;
    }
};