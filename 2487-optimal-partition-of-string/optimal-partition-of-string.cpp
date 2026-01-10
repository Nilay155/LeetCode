class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        vector<int> count(26,0);
        int partitions = 0;
        for(int i = 0 ; i < n ; i++) {
            if(count[s[i]-'a'] > 0) {
                partitions += 1;
                count = vector<int>(26,0);
            }
            count[s[i]-'a'] += 1;
        }
        partitions += 1;
        return partitions;
    }
};