class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int n = allowed.size(), m = words.size();
        vector<bool> vis(26,false);
        for(char ch : allowed) {
            vis[ch-'a'] = true;
        }
        int count = 0;
        for(int i = 0 ; i < m ; i++) {
            vector<bool> check(26,false);
            for(char ch : words[i]) {
                check[ch-'a'] = true;
            }
            bool flag = true;
            for(int k = 0 ; k < 26 ; k++) {
                if(!vis[k] && check[k]) {
                    flag = false;
                    break;
                }
            }
            if(flag) count += 1;
        }
        return count;
    }
};