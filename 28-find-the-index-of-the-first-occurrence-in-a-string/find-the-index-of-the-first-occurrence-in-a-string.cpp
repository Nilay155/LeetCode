class Solution {
private:
    vector<int> computeLPS(string str) {
        int prev = 0, curr = 1, n = str.length();
        vector<int> lps(n,0);

        while(curr < n) {
            if(str[curr] == str[prev]) {
                lps[curr] = 1 + prev;
                curr += 1;
                prev += 1;
            } else if(prev == 0) {
                prev = 0;
                lps[curr] = 0;
                curr += 1;
            } else {
                prev = lps[prev - 1];
            }
        }
        return lps;
    }
    int kmp(string text,string patt) {
        vector<int> lps = computeLPS(patt);
        int t = 0, p = 0, n = text.length(), m = patt.length();

        while(t < n) {
            if(text[t] == patt[p]) {
                t += 1;
                p += 1;
            } else if(p == 0) {
                t += 1;
            } else {
                p = lps[p-1];
            }

            if(p >= m) return t-m;
        }
        return -1;
    }
    int rabinKarp(string text,string patt) {
        int n = text.length(), m = patt.length();
        int h = 1, t = 0, p = 0, d = 31, mod = 1e9 + 7;
        
        for(int k = 0 ; k < m-1 ; k++) h = (h*10) % mod;
        
        int i = 0;
        for(i = 0 ; i < m ; i++) {
            t = (t + (d * text[i]-'a')) % mod;
            p = (p + (d * patt[i]-'a')) % mod;
        }

        if(t == p) return 0;
        for(int j = i ; j < n ; j++) {
            t = (t - (h * text[j-m]-'a') + d * text[j]-'a') % mod;
            if(t == p) return j-m;
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        return kmp(haystack,needle);
    }
};