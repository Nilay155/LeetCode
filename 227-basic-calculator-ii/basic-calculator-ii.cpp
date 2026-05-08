class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int curr = 0, last = 0, ans = 0;
        char opr = '+';
        for(int i = 0 ; i < n ; i++) {

            if(isdigit(s[i])) {
                curr = curr * 10 + (s[i] - '0');
            }

            if((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {

                if(opr == '*') {
                    last = last * curr;
                } else if(opr == '/') {
                    last = last / curr;
                } else if(opr == '-') {
                    ans += last;
                    last = -curr;
                } else {
                    ans += last;
                    last = curr;
                }
                curr = 0;
                opr = s[i];
            }
        }
        return ans + last;
    }
};