class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();

        unordered_map<char,int> S,T;
        int l = 0, r = 0, len = n+1, idx = -1,count = 0;
        for(int i = 0 ; i < m ; i++) T[t[i]] += 1;

        while(r < n) {

            S[s[r]] += 1;
            if(T.find(s[r]) != T.end() && S[s[r]] == T[s[r]]) count += 1;

            while(l <= r && count == T.size()) {
                if(r - l + 1 < len) {
                    len = r - l + 1;
                    idx = l;
                }
                S[s[l]] -= 1;
                if(T.find(s[l]) != T.end() && S[s[l]] < T[s[l]]) {
                    count -= 1;
                }
                l += 1;
            }
            r += 1;
        }
        if(idx == -1) return "";
        return s.substr(idx,len);
    }
};