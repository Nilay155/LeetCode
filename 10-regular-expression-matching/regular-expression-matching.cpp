class Solution {
public:
    bool check(string &p,int j,int m) {
        
        int k = j;
        while(k < m) {
            if(k+1 < m) {
                if(p[k+1] != '*') return false;
                k += 2;
            } else {
                return false;
            }
        }
        return true;
    }
    bool dfs(string &s,string &p,int i,int j,int n,int m) {
        if(i >= n && j >= m) return true;
        if(i >= n) return check(p,j,m);

        int option1 = false;
        int option2 = false;
        int option3 = false;
        
        if(j+1 < m && p[j+1] == '*') {
            option3 |= dfs(s,p,i,j+2,n,m);
                for(int k = i ; k < n; k++) {
                    if(s[k] == p[j] || p[j] == '.') {
                        option3 |= dfs(s,p,k+1,j+2,n,m);
                    } else {
                        break;
                    }
                }
        
        }
        else if(s[i] == p[j]) {
            option1 = dfs(s,p,i+1,j+1,n,m);
        } else if(p[j] == '.') {
            option2 = dfs(s,p,i+1,j+1,n,m);
        } else {
            return false;
        }
        return option1 || option2 || option3;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        int i = 0 , j = 0;

        return dfs(s,p,i,j,n,m);
    }
};