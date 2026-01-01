class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lower(26,-1),upper(26,n);

        for(int i = 0 ; i < n ; i++) {
            if(isupper(word[i])) {
                upper[word[i]-'A'] = min(upper[word[i]-'A'],i);
            } else {
                lower[word[i]-'a'] = max(lower[word[i]-'a'],i);
            }
        }

        int c = 0;
        for(int i = 0 ; i < 26 ; i++) {
            if(lower[i] != -1 && upper[i] != n) {
                if(lower[i] < upper[i]) c += 1;
            }
        }
        return c;
    }
};