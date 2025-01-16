class Solution {
public:
    static bool cmp(string &a,string &b) {
        return a.size() < b.size();
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        
        // sort(words.begin(),words.end(),cmp);
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            int k = words[i].size();
            for(int j = i+1 ; j < n ; j++) {
                int m = words[j].size();
                if(k > m) continue;
                if(words[j].substr(0,k) == words[j].substr(m-k,k) && words[j].substr(0,k) == words[i]) ans++;
            }
        }
        return ans;
    }
};