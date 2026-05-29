class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> lower(26,-1), upper(26,n);

        for(int i = 0 ; i < n ; i++) {
            char ch = word[i];
            if(isupper(ch)) {
                upper[ch - 'A'] = min(i,upper[ch - 'A']);
            } else {
                lower[ch - 'a'] = max(i,lower[ch - 'a']);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++) {
            if(lower[i] < upper[i] && lower[i] != -1 && upper[i] != n) {
                ans += 1;
            }
        }
        return ans;
    }
};