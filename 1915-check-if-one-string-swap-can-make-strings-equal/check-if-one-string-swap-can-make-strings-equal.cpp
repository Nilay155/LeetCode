class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int c = 0;
        vector<int> count(26,0);
        for(char ch : s1) count[ch-'a']++;
        for(char ch : s2) count[ch-'a']--;
        for(int i = 0 ; i < 26 ; i++) {
            if(count[i] < 0 || count[i] > 0) return false;
        }
        for(int i = 0 ; i < n ; i++) {
            if(s1[i] != s2[i]) c++;
        }
        return c <= 2;
    }
};