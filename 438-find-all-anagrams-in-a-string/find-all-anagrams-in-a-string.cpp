class Solution {
public:
    Solution() {
 std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
}
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), k = p.length();
        unordered_map<char,int> patt,text;

        for(char ch : p) patt[ch]++;
        int total = patt.size();
        int count = 0, l = 0;
        vector<int> res;

        for(int r = 0 ; r < n ; r++) {
            text[s[r]] += 1;
            if(patt.find(s[r]) == patt.end()) {
                l = r+1;
                text.clear();
                count = 0;
            }
            if(patt.find(s[r]) != patt.end()) {
                if(text[s[r]] == patt[s[r]]) count += 1;
                while(text[s[r]] > patt[s[r]]) {
                    if(text[s[l]] == patt[s[l]]) count -= 1;
                    text[s[l]] -= 1;
                    if(text[s[l]] == 0) text.erase(s[l]);
                    l += 1;
                }
            }
            if(count == total) {
                res.push_back(l);
            }
        }
        return res;
    }
};