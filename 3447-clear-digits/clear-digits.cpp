class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        string ans;

        int i = 0;
        while(i < n) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                ans.push_back(s[i]);
            } else {
                // digits
                if(!ans.empty()) ans.pop_back();
            }
            i++;
        }
        return ans;
    }
};