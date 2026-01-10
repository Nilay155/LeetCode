class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> count(26,0);
        for(char ch : s) count[ch-'a']++;

        for(int i = 0 ; i < 26 ; i++) {
            int c = count[i];

            if(c > 2) {
                int rem = c - 1;
                count[i] = 1 + rem % 2;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++) ans += count[i];
        return ans;
    }
};