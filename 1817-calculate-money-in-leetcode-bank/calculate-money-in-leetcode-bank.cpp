class Solution {
public:
    int totalMoney(int n) {
        
        int q = n/7, r = n % 7;
        int k1 = 7 * 4 * q;
        int k2 = ((q)*(q-1)/2)* 7;
        int k3 = (r * (r+1) / 2) + (q * r);
        int ans = k1 + k2 + k3;
        return ans;
    }
};