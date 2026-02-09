class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char,int> counts;
        int l = 0, r = 0;
        int longestSubstring = 0;
        while(r < n) {
            counts[s[r]] += 1;
            while(l < r && counts[s[r]] > 1) {
                counts[s[l]] -= 1;
                l += 1;
            }
            longestSubstring = max(longestSubstring,r - l + 1);
            r += 1;
        }
        return longestSubstring;
    }
};