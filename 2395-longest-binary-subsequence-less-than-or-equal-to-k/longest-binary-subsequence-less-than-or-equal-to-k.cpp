class Solution {
private:
    int binaryToDecimal(vector<int> &dp,int k) {
        long long res = 0;
        for(int i = 0 ; i < dp.size() ; i++) {
            if(dp[i])
                res = res * 2LL + (dp[i]-1);
            
            if(res > k) return k+1;
        }
        return res;
    }
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();

        vector<int> dp(n,0);
        for(int i = 0 ; i < n ; i++) if(s[i] == '0') dp[i] = 1;

        for(int i = n-1 ; i >= 0 ; i--) {

            if(s[i] == '1') {
                dp[i] = 2;
                int temp = binaryToDecimal(dp,k);
                if(temp > k) {
                    dp[i] = 0;
                    break;
                }
            }
        }
        int res = 0;
        for(int i = 0 ; i < dp.size() ; i++) {
            if(dp[i]) res += 1;
        }
        return res;
    }
};