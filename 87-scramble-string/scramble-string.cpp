class Solution {
private:
    int dp[31][31][31];
    bool equalStr(string &s,string &t,int i,int j,int l) {
        return s.compare(i,l,t,j,l) == 0;
    }
    bool f(string &s,string &t,int i,int j,int l) {

        if(dp[i][j][l] != -1) return dp[i][j][l];

        if(equalStr(s,t,i,j,l)) return dp[i][j][l] = 1;

        vector<int> count(26,0);

        for(int x = 0 ; x < l ; x++) {
            count[s[i + x]-'a']++;
            count[t[j + x]-'a']--;
        }

        for(int cnt : count) {
            if(cnt != 0) return dp[i][j][l] = 0;
        }

        for(int k = 1 ; k < l ; k++) {

            if(f(s,t,i,j,k) & f(s,t,i+k,j+k,l-k)) return dp[i][j][l] = true; // no-swap

            if(f(s,t,i+k,j,l-k) & f(s,t,i,j+l-k,k)) return dp[i][j][l] = true;; // swap
        }
        return dp[i][j][l] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n != m) return false;

        memset(dp,-1,sizeof(dp));
        return f(s1,s2,0,0,n);
    }
};