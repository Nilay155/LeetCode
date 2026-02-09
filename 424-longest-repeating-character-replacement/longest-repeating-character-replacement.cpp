class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> counts(26,0);
        int l = 0, r = 0,maxi = 0, longestSubstring = 0;
        while(r < n) {
            counts[s[r]-'A'] += 1;
            maxi = max(maxi,counts[s[r]-'A']);

            while(l < r && (r - l + 1 - maxi) > k) {
                counts[s[l]-'A'] -= 1;
                maxi = max(maxi,counts[s[l]-'A']);
                l += 1;
            }
            longestSubstring = max(longestSubstring,r - l + 1);
            r += 1;
        }
        return longestSubstring;
    }
};