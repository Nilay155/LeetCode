class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int ans = 10;
        int k = 9,mul = 1;
        for(int i = 2 ; i <= n ; i++) {
            mul *= k;
            ans += (9 * mul);
            k--;
        }
        return ans;
    }
};