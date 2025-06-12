class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt1(26),cnt2(26);

        for(char ch : s) cnt1[ch-'a']++;
        for(char ch : t) cnt2[ch-'a']++;

        for(int i = 0 ; i < 26 ; i++) {
            if(cnt1[i] != cnt2[i]) return false; 
        }
        return true;
    }
};