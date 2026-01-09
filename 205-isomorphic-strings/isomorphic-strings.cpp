class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char,char> S,T;

        for(int i = 0 ; i < n ; i++) {

            if(S.find(s[i]) != S.end()) {
                if(S[s[i]] != t[i])
                    return false;
            } else if(T.find(t[i]) != T.end()) {
                if(T[t[i]] != s[i]) 
                    return false;
            } else {
                S[s[i]] = t[i];
                T[t[i]] = s[i];
            }
        }
        return true;
    }
};