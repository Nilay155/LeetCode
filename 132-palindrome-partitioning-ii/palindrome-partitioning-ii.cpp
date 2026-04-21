class Solution {
private:
    int dp[2001];
    int minCuts(string &s,int i,int &n,vector<vector<bool>> &palindromes) {
        if(i >= n) 
            return -1;
        if(dp[i] != -1) return dp[i];

        int ans = n - 1;
        for(int j = i ; j < n ; j++) {
            if(palindromes[i][j]) {
                int rec = 1 + minCuts(s,j + 1,n,palindromes);
                ans = min(ans,rec);
            }
        }
        return dp[i] = ans;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> palindromes(n,vector<bool>(n,false));
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < n ; i++) {
            // odd plaindromes
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                palindromes[l][r] = true;
                l -= 1, r += 1;
            }

            // even plaindromes
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                palindromes[l][r] = true;
                l -= 1, r += 1;
            }
        }
        return minCuts(s,0,n,palindromes);
    }
};