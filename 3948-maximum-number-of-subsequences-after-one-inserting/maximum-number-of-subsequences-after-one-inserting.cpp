typedef long long ll;
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.length();

        vector<ll> l(n),t(n);
        l[0] = s[0] == 'L' ? 1 : 0;
        for(int i = 1 ; i < n ; i++) {
            if(s[i] == 'L')
                l[i] = 1 + l[i - 1];
            else
                l[i] = l[i - 1];
        }
        t[n - 1] = s[n - 1] == 'T' ? 1 : 0;
        for(int i = n - 2 ; i >= 0 ; i--) {
            if(s[i] == 'T')
                t[i] = 1 + t[i + 1];
            else
                t[i] = t[i + 1];
        }
        ll maxi = 0;
        for(int i = 1 ; i < n - 1 ; i++) {
            if(s[i] == 'C') {
                ll L = l[i - 1];
                ll T = t[i + 1];
                maxi += (L * T);
            }
        }
        // cout << maxi << "\n";
        // Case-3 : Inserting 'C' at all positions and checking
        ll res3 = 0;
        for(int i = 0 ; i < n - 1 ; i++) {
            // Additional C inserted
            // c = i + 1
            ll L = l[i];
            ll T = t[i + 1];
            res3 = max(res3,maxi + L * T);
        }
        if(n == 2) {
            ll L = l[0];
            ll T = t[1];
            res3 = L * T;
        }
        // Case-2: Inserting 'T' at the end of the string
        ll res2 = 0;
        for(int i = 1 ; i < n ; i++) {
            if(s[i] == 'C') {
                ll L = l[i - 1];
                ll T =(i+1 < n ? t[i + 1] : 0) + 1;
                res2 += (L * T);
            }
        }
        if(n == 2) {
            ll L = l[0];
            res2 = L * (s[1] == 'C' ? 1 : 0);
        }
        // Case-1 : Inserting 'L' at the start of the string
        ll res1 = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            if(s[i] == 'C') {
                ll L = (i-1 >= 0 ? l[i - 1] : 0) + 1;
                ll T = t[i + 1];
                res1 += (L * T);
            }
        }
        if(n == 2) {
            ll T = t[1];
            res1 = T * (s[0] == 'C' ? 1 : 0);
        }
        cout << maxi << " : " << res1 << " : " << res2 << " : " << res3 << "\n"; 
        maxi = max({maxi,res1,res2,res3});
        return maxi;
    }
};