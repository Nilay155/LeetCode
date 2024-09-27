class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(string &s,int i,int &n,int &k,vector<int> &dp) {
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        long long int res = 0;
        long long num = 0;
 
        for(int j = i ; j < n ; j++){ 
            num = num * 10 + s[j] - '0';
            if(num > k) break;
            if(j-i+1 > 10) break;
            // long long int temp = stoll(s.substr(i,j-i+1));
            if(num >= 1 && num <= k) {
                long long int ans = solve(s,j+1,n,k,dp)%MOD;
                res += ans%MOD;
            }
        }
        return dp[i] = res%MOD;
    }
    int numberOfArrays(string s, int k) {
        // range [1,k]
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(s,0,n,k,dp)%MOD;
    }
};