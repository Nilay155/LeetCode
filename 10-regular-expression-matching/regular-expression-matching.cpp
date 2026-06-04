class Solution {
public:
    bool check(string &p,int j) {

        for(int k = j ; k < p.length() ; k++) {
            if(p[k] != '*') {
                if(k + 1 < p.length() && p[k + 1] == '*')
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
    int dp[21][21];
private:
    bool match(string &s,string &p,int i,int j) {
        if(i >= s.length()) {

            if(check(p,j)) {
                return true;
            } else {
                return false;
            }
        }

        if(i >= s.length() || j >= p.length())
            return false;
        if(dp[i][j] != -1) 
            return dp[i][j];

        bool ans = false;
        if(j + 1 < p.length() && p[j + 1] == '*') {
            if(s[i] == p[j] || p[j] == '.') {
                ans = ans | match(s,p,i + 1,j);  
            } 
            ans = ans | match(s,p,i,j + 2);
        } else if(s[i] == p[j]) {
            ans = ans | match(s,p,i + 1,j + 1);
        } else if(s[i] != p[j] && p[j] == '.') {
            ans = ans | match(s,p,i + 1,j + 1);
        } else {
            return false;
        }
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return match(s,p,0,0);
    }
};