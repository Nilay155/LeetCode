class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string,int> counts;

        int l = 0, r = 0;

        while(r < n) { // O(n)
            if(r - l + 1 >= 10) {
                counts[s.substr(l,r-l+1)] += 1; // O(1)
                l += 1;
            }
            r += 1;
        }
        vector<string> ans;
        for(auto [str,count] : counts) {
            if(count > 1) ans.push_back(str);
        }
        return ans;
    }
};