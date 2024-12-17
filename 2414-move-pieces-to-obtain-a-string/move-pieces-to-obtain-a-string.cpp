class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.length();

        int i = 0, j = 0;

        while(i <= n && j <= n) {
            while(s[i] == '_') i++;
            while(t[j] == '_') j++;

            if(s[i] != t[j]) return 0;

            if(s[i] == 'L') {
                if(i >= j);
                else return 0;
            }
            else if(s[i] == 'R') {
                if(j >= i);
                else return 0;
            }
            i++;
            j++;
        }
        return 1;
    }
};