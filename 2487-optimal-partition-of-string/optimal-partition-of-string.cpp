class Solution {
public:
    int partitionString(string s) {
        
        int n = s.length();
        vector<int> count(26,0);

        int partitions = 0;

        for(int i = 0 ; i < n ; i++) {
            char ch = s[i];

            if(count[ch-'a'] == 1) {
                count = vector<int>(26,0);
                count[ch-'a']++;
                partitions++;
            } else {
                count[ch-'a']++;
            }
        }

        return ++partitions;
    }
};