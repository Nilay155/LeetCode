class Solution {
private:
    string ans;
    bool f(int k,int &n,string s) {
        if(k == n) {
            ans = s;
            return true;
        }

        int m = s.length(), count = 0;
        string newStr = "";
        char ch;

        for(int r = 0 ; r < m ; r++) {
            if(count == 0) {
                ch = s[r];
                count += 1;
            } else if(ch == s[r]) {
                count += 1;
            } else {
                newStr += to_string(count) + ch;
                ch = s[r];
                count = 1;
            }
        }
        newStr += to_string(count) + ch;

        if(f(k + 1,n,newStr))
            return true;
        return false;
    }
public:
    string countAndSay(int n) {
        f(1,n,"1");
        return ans;
    }
};