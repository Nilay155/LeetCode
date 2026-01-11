class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.length();
        unordered_map<string,int> substrings;
        int j = n / k;
        for(int i = 0 ; i < n ; i += j) {
            substrings[s.substr(i,j)] += 1;
        }
        for(int i = 0 ; i < n ; i += j) {
            substrings[t.substr(i,j)] -= 1;
        }

        for(auto [str,count] : substrings) {
            if(count > 0 || count < 0) return false;
        }
        return true;
    }
};