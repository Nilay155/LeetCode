class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        string r = s;
        reverse(r.begin(),r.end());

        long long f = 0, b = 0, d = 29, mod = 1e9 + 7, p = 1;
        int last = -1;

        for(int i = 0 ; i < n ; i++) {
            f = (f * d + s[i]-'a') % mod;
            b = (b + (s[n-i-1]-'a') * p) % mod;
            p = (p * d) % mod;

            // cout << f << " : " << b << endl;  
            if(f == b && i != n-1) last = i;
        }

        // cout << last << endl;
        if(last == -1) return "";
        else return s.substr(0,last + 1);
    }
};