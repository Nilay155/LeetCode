class Solution {
public:
    static bool cmp(string &a,string &b) {
        return a.size() < b.size();
    }
    bool stringMatching(string &patt,string &text) {
        
        int n = patt.size(), m = text.size();

        for(int i = 0 ; i < m-n+1 ; i++) {

            if(text.substr(i,n) == patt) return 1;
        }
        return 0;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();

        sort(words.begin(),words.end(),cmp);
        vector<string> res;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                if(stringMatching(words[i],words[j])) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};