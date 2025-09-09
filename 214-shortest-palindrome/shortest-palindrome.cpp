class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();

        long long f = 0, b = 0, d = 29, last = -1, mod = 1e9 + 7, p = 1;

        for(int i = 0 ; i < n ; i++) {
            f = ((long long)(f * d) + s[i]-'a') % mod;
            b = (b + (s[i]-'a') * p) % mod;
            p = (long long)(p * d) % mod;

            if(f == b) last = i;
        }
        cout << last << endl;
        string add = s.substr(last+1,n);
        reverse(add.begin(),add.end());
        return add + s;
    }
};