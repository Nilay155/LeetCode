typedef long long ll;
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(9,vector<int>(10,0));

        for(int i = 0 ; i < n ; i++) {
            string s = to_string(nums[i]);
            for(int j = 0 ; j < s.length() ; j++) {
                dp[j][s[j]-'0'] += 1;
            }
        }

        long long  ans = 0;
        for(int i = 0 ; i < 9 ; i++) {
            for(int j = 0 ; j < 10 ; j++) {
                for(int k = j+1 ; k < 10 ; k++) {
                    long long pairs = (long long)(dp[i][j]) * (long long)(dp[i][k]);
                    ans += pairs;
                }
            }
        }
        return ans;
    }
};