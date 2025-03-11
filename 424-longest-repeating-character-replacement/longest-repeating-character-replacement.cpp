class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> count(26,0);
        int l = 0;
        int maxi = 0, res = 0;
        for(int r = 0 ; r < n ; r++) {
            count[s[r]-'A'] += 1;
            maxi = max(maxi,count[s[r]-'A']);

            while((r-l+1)-maxi > k) {
                count[s[l]-'A'] -= 1;
                l += 1;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};