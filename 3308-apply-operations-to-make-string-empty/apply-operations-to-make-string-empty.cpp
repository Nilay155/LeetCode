class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.length();

        vector<int> count(26,0);
        for(char ch : s) count[ch-'a'] += 1;

        int maxi = 0;
        for(int i = 0 ; i < 26 ; i++) {
            maxi = max(maxi,count[i]);
        }

        if(maxi == 0) return "";
        for(int i = 0 ; i < 26 ; i++) {
            if(count[i] != maxi) count[i] = 0;
        }

        string ans;
        for(int i = 0 ; i < n ; i++) {
            if(count[s[i]-'a'] == 1) {
                ans.push_back(s[i]);
            } 
            count[s[i]-'a'] -= 1;
        }
        return ans;


    }
};