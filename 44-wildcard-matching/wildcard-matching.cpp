class Solution {
public:
    bool check(string &s,int j,int m) {

        for(int k = j ; k < m ; k++) {
            if(s[k] != '*') return false;
        }
        return true;
    }
    bool dfs(string &s1,string &s2,int i,int j,int &n,int &m,vector<vector<int>> &dp) {

        if(i >= n && j >= m) return true;
        if(i >= n) {
            if(check(s2,j,m)) return true;
            else return false;
        }
        if(j >= m) return false;

        if(dp[i][j] != -1) return dp[i][j];

        int option1 = false;
        int option2 = false;
        int option3 = false;

        if(s1[i] == s2[j]) {
            option1 = dfs(s1,s2,i+1,j+1,n,m,dp);
        } else if(s2[j] == '?') {
            option2 = dfs(s1,s2,i+1,j+1,n,m,dp);
        } else if(s2[j] == '*') {
            option3 = dfs(s1,s2,i+1,j,n,m,dp) || dfs(s1,s2,i,j+1,n,m,dp);
        } else { 
            return false;
        }

        return dp[i][j] =  option1 || option2 || option3;
    }

    bool isPossible(string s,int i,int m) {

        for(int j = i ; j < m ; j++) {
            if(s[j] != '*') return false;
        }
        return true;
    }
    bool tabulation(string s,string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int i = 0 ; i < m ; i++) {
            dp[n][i] = isPossible(p,i,m);
        }

        for(int i = 0 ; i < n ; i++) {
            dp[i][m] = false;
        }
        dp[n][m] = true;

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int j = m-1 ; j >= 0 ; j--) {

                if(s[i] == p[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else if(p[j] == '?') {
                    dp[i][j] = dp[i+1][j+1];
                } else if(p[j] == '*') {
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];

    }
    bool isMatch(string s, string p) {
        
        int n = s.length();
        // int m = p.length();
        
        // int i = 0, j = 0;
        // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        // return dfs(s,p,i,j,n,m,dp);
        return tabulation(s,p);
    }
};