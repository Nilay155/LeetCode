class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        
        int num = pow(10,n);
        long long res = 0;

        vector<int> dp(num+1,0);
        for(int i = 0 ; i <= 9 ; i++) dp[i] = 1;

        for(int i = 10 ; i <= num ; i++) {
            
            int temp = i/10;
            int lastDigit = i%10;
            int flag = 0;

            while(temp) {
                int digit = temp%10;
                if(digit == lastDigit) {
                    flag = 1;
                    break;
                }
                temp /= 10;
            }
            if(!flag && dp[i/10] == 1) {
                // cout << i << "   " ;
                dp[i] = 1;
                res += 1;
            }
        }
        return res+10;
    }
};