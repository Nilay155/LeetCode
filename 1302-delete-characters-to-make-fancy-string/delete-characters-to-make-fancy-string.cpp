class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        
        string ans;
        int cnt = 0;
        char prev;

        for(char ch : s) {
            if(cnt == 2 && ch == prev) {
                // skip
            } else {
                ans.push_back(ch);
                if(ch == prev) {
                    cnt++;
                } else {
                    cnt = 1;
                    prev = ch;
                }
            }
        }
        return ans;
    }
};