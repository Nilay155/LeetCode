class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& s) {
        
        int n = s.size(), groups = 0;

        for(int i = 0 ; i < n - 2 ; i++) {
            if(s[i] == s[i + 2] && s[i] != s[i + 1]) {
                groups += 1;
            }
        }
        if(s[n - 2] == s[0] && s[n - 1] != s[0]) 
            groups += 1;
        if(s[n - 1] == s[1] && s[1] != s[0])
            groups += 1;
        return groups;
    }
};