class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26,0);
        int n = s.length();
        for(char ch : s) count[ch-'a']++;

        string ans;
        for(int i = 0 ; i < order.length() ; i++) {
            if(count[order[i]-'a']) {
                ans += string(count[order[i]-'a'],order[i]);
                count[order[i]-'a'] = 0;
            }
        }
        for(int i = 0; i < 26 ; i++) {
            if(count[i]) {
                ans += string(count[i],i + 'a');
                count[i] = 0;
            }
        }
        return ans;
    }
};