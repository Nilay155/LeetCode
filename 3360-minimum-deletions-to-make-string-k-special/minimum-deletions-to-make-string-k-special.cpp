class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> mpp;
        for(char ch : word) mpp[ch]++;

        int ans = 1e9;
        for(auto& it1 : mpp) {
            int freq = it1.second;
            int res = 0;
            for(auto& it2 : mpp) {
                if(freq > it2.second) {
                    res += it2.second;
                } else if(it2.second - freq > k){
                    res += (it2.second-freq-k);
                }
            }   
            ans = min(ans,res);
        }
        return ans;
    }
};