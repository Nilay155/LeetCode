class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // atmost once
        int n = str1.length(), m = str2.length();
        int i = 0, j = 0;

        while(i < n && j < m) {
            int k1 = str1[i] - 'a', k2 = (str1[i] - 'a' + 1) % 26;
            int c = str2[j] - 'a';

            if(k1 == c || k2 == c) {
                j += 1;
            } 
            i += 1;
        }
        return j == m;
    }
};