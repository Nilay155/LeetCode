class Solution {
private:
    // int dp[31][31][31];
    bool equalStr(string &s,string &t,int i,int j,int l) {
        return s.compare(i,l,t,j,l) == 0;
    }
    // bool f(string &s,string &t,int i,int j,int l) {

    //     if(dp[i][j][l] != -1) return dp[i][j][l];

    //     if(equalStr(s,t,i,j,l)) return dp[i][j][l] = 1;

    //     vector<int> count(26,0);

    //     for(int x = 0 ; x < l ; x++) {
    //         count[s[i + x]-'a']++;
    //         count[t[j + x]-'a']--;
    //     }

    //     for(int cnt : count) {
    //         if(cnt != 0) return dp[i][j][l] = 0;
    //     }

    //     for(int k = 1 ; k < l ; k++) {

    //         if(f(s,t,i,j,k) & f(s,t,i+k,j+k,l-k)) return dp[i][j][l] = true; // no-swap

    //         if(f(s,t,i+k,j,l-k) & f(s,t,i,j+l-k,k)) return dp[i][j][l] = true;; // swap
    //     }
    //     return dp[i][j][l] = false;
    // }

    bool anagramCheck(string &s,string &t,int i,int j,int l) {
        vector<int> count(26,0);

        for(int x = 0 ; x < l ; x++) {
            count[s[i + x]-'a']++;
            count[t[j + x]-'a']--;
        }

        for(int cnt : count) {
            if(cnt != 0) return false;
        }
        return true;
    

    }
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n != m) return false;

        // memset(dp,-1,sizeof(dp));
        // return f(s1,s2,0,0,n);

        vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(n+1,vector<bool>(n+1,false)));

        for(int l = 0 ; l <= n ; l++) {
            // i se l => len
            for(int i = 0 ; i+l <= n ; i++) {
                // j se l => len
                for(int j = 0 ; j+l <= n ; j++) {

                    if(equalStr(s1,s2,i,j,l))
                        dp[l][i][j] = true;
                }   
            }
        }

        for(int l = 1 ; l <= n ; l++) {
            for(int i = 0 ; i + l <= n ; i++) {
                for(int j = 0 ; j + l <= n ; j++) {
                    // checking if they are anagrams
                    if(anagramCheck(s1,s2,i,j,l)) {

                        for(int k = 1; k < l ; k++) {
                            
                            // no-swapping
                            if(dp[l - k][i + k][j + k] && dp[k][i][j])
                                dp[l][i][j] = true;
                            
                            // swapping
                            if(dp[l - k][i + k][j] && dp[k][i][j + l - k])
                                dp[l][i][j] = true;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};