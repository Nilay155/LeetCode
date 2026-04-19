class Solution {
private:
    vector<int> getForwardHash(const string& s) {
        const int base = 27, mod = 1000000007;
        int n = s.size();

        vector<int> forwardHash(n);
        long long h = 0;

        for (int i = 0; i < n; i++) {
            h = (h * base + (s[i] - 'a' + 1)) % mod;
            forwardHash[i] = (int)h;
        }
        return forwardHash;
    }

    vector<int> getBackwardHash(const string& s) {
        const int base = 27, mod = 1000000007;
        int n = s.size();

        vector<int> backwardHash(n);
        long long h = 0;

        for (int i = n - 1; i >= 0; i--) {
            h = (h * base + (s[i] - 'a' + 1)) % mod;
            backwardHash[n - i - 1] = (int)h;
        }
        return backwardHash;
    }
    vector<int> buildPower(int n) {
        const int base = 27, mod = 1000000007;

        vector<int> powerBase(n + 1);
        powerBase[0] = 1;

        for (int i = 1; i <= n; i++) {
            powerBase[i] = (1LL * powerBase[i - 1] * base) % mod;
        }
        return powerBase;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while(l < r) {
            if(s[l] != s[r])
                return false;
            l += 1, r -= 1;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> forward(words.size()), backward(words.size());
        vector<int> powerBase = buildPower(10000);
        vector<bool> palindromes(words.size(),false);

        const int mod = 1000000007;
        
        for(int i = 0 ; i < words.size() ; i++) {
            vector<int> f = getForwardHash(words[i]);
            vector<int> b = getBackwardHash(words[i]);
            palindromes[i] = isPalindrome(words[i]);
            forward[i] = f;
            backward[i] = b;
        }
        
        vector<vector<int>> ans;
        for(int i = 0 ; i < words.size() ; i++) {
            for(int j = 0 ; j < words.size() ; j++) {
                if(i == j) continue;
                int u = words[i].length(), v =  words[j].length();
                if(u == 0 || v == 0) {
                    if(palindromes[i] && palindromes[j]) 
                        ans.push_back({i,j});
                    continue;
                }
                int len = u + v;
                int fh = len / 2, sh = len / 2;
                int h1 = -1, h2 = -2;
                
                if(u >= fh) {
                    h1 = forward[i][fh - 1];
                } else {
                    // u < fh
                    int r = fh - u;
                    int h3 = forward[i][u - 1];
                    int h4 = forward[j][r - 1];
                    h1 = (1LL * h3 * powerBase[r] + h4) % mod;
                }

                if(v >= sh) {
                    h2 = backward[j][sh - 1];
                } else {
                    int r = sh - v;
                    int h3 = backward[i][r - 1];
                    int h4 = backward[j][v - 1];
                    h2 = (1LL * h4 * powerBase[r] + h3) % mod;
                }
                // cout << h1 << "   " << h2 << "\n";
                if(h1 == h2) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};