class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // brute force -> O(n^3)
        int n = words.size();
        string reference = words[0];
        vector<int> ans(26,0);

        for(char ch : reference) {
            ans[ch-'a']++;
        }

        for(int i = 1 ; i < n ; i++) {
            vector<int> cnt(26,0);
            for(int j = 0 ; j < words[i].length() ; j++) {
                cnt[words[i][j]-'a']++;
            }

            for(int k = 0 ; k < 26 ; k++) {
                if(ans[k] && cnt[k]) {
                    ans[k] = min(ans[k],cnt[k]);
                } else {
                    ans[k] = 0;
                }
            }
        }

        vector<string> res;
        for(int k = 0 ; k < 26 ; k++) {
            while(ans[k]--) {
                res.push_back(string(1,k + 'a'));
            }
        }
        return res;
    }
};