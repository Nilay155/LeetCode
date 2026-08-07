class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int ans = 10;
        
        for(int i = 2 ; i <= n ; i++) {

            int k = 10, j = i, mul = 1;
            while(j--) {
                mul *= (k >= 10 ? 9 : k);
                k--;
            }
            ans += mul;
        }
        return ans;
    }
};