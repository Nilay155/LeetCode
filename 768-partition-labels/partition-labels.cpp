class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
    vector<int> ans;
    vector<int> position(26,0);
    for(int i = 0 ; i < n ; i++) {
        char ch = s[i];
        position[ch-'a'] = i;
    }
    int currIndex = 0, latestPartition = 0, prefix = 0;
    while(currIndex < n) {
        latestPartition = max(latestPartition,position[s[currIndex]-'a']);
        if(currIndex == latestPartition) {
            int length =  latestPartition - prefix + 1;
            ans.push_back(length);
            prefix += length;
            latestPartition = currIndex + 1;
        }
        currIndex += 1;
    }
    return ans;
    }
};