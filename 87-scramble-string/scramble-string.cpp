class Solution {
private:
    unordered_map<string,bool> dp;

    string generateKey(string s,string t) {
        return s + "#" + t;
    }

    bool f(string s,string t) {
        if(s == t)
            return true;

        if(s.length() != t.length())
            return false;

        string key = generateKey(s,t);

        if(dp.count(key))
            return dp[key];

        // string a = s, b = t;
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());

        // if(a != b)
        //     return dp[key] = false;

        int n = s.length();

        for(int i = 1; i < n; i++) {

            bool noSwap =
                f(s.substr(0,i), t.substr(0,i)) &&
                f(s.substr(i), t.substr(i));

            bool swap =
                f(s.substr(0,i), t.substr(n-i,i)) &&
                f(s.substr(i), t.substr(0,n-i));

            if(noSwap || swap)
                return dp[key] = true;
        }

        return dp[key] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        return f(s1,s2);
    }
};