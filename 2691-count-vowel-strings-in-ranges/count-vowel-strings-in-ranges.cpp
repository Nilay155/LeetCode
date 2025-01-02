class Solution {
public:
    bool vowel(string s) {
        int k = s.length()-1;
        if((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
        && (s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' || s[k] == 'u'))
            return true;
        else 
            return false;
    }
    void func(vector<string> &words,vector<int> &prefix,int n) {
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            if(vowel(words[i])) {
                prefix[i] = ++count;
            } else {
                prefix[i] = count;
            }
        }
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> prefix(n);
        func(words,prefix,n);

        vector<int> ans(m);
        for(int i = 0 ; i < m ; i++) {

            int ai = queries[i][0];
            int bi = queries[i][1];

            int res = 0;

            if(ai-1 >= 0) {
                res = prefix[bi]-prefix[ai-1];
            } else {
                res = prefix[bi];
            }
            ans[i] = res;
        }
        return ans;
    }
};