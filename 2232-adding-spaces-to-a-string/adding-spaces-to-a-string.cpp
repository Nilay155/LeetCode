class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();

        string ans;
        int j = 0;
        if(j < m && spaces[j] == 0) {
            ans.push_back(' ');
            j++;
        }
        for(int i = 0 ; i < n ; i++) {
            ans.push_back(s[i]);
            if(j < m && spaces[j] == (i+1)) {
                j++;
                ans.push_back(' ');
            }
        }
        return ans;
    }
};