class Solution {
private:
    string ans;
    bool solve(int n,int &k,string s) {

        if(n == 0 && k == 1) {
            ans = s;
            return true;
        }
        if(n == 0) {
            k -= 1;
            return false;
        }

        for(char ch = 'a' ; ch <= 'c' ; ch++) {
            if(s.empty()) {
                if(solve(n-1,k,s+ch)) return true;
            } else {
                if(s.back() != ch) {
                    if(solve(n-1,k,s+ch)) return true;
                }
            }
        }
        return false;
    }
public:
    string getHappyString(int n, int k) {
        // a b c 
        // s[i] != s[i+1] 1-indexed
        solve(n,k,"");
        return ans;
    }
};