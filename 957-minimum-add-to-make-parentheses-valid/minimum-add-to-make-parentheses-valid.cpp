class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();

        int open = 0;
        int ans = 0;

        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '(') {
                open++;
            }
            else {
                open--;
                if(open < 0) {
                    open = 0;
                    ans++;
                }
            }
        }
        if(open > 0) ans += open;
        return ans;
    }
};