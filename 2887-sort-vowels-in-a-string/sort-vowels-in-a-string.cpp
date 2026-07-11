class Solution {
private:
    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }
public:
    string sortVowels(string s) {
        int n = s.length();
        string t = s;
        vector<pair<int,char>> asciiValues;
        for(int i = 0 ; i < n ; i++) {
            if(isVowel(s[i])) {
                asciiValues.push_back({s[i] - '\0',s[i]});
                t[i] = '.';
            } 
        }
        sort(asciiValues.begin(),asciiValues.end());
        int i = 0,j = 0, m = asciiValues.size();
        while(i < n) {
            if(t[i] == '.') {
                t[i] = asciiValues[j].second;
                j += 1;
            }
            i += 1;
        }
        return t;
    }
};