class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        
        int partitions = 0, mask = 0;
        for(int i = 0 ; i < n ; i++) {
            char ch = s[i];

            if(mask & (1 << (ch-'a'))) {
                partitions += 1;
                mask = 0;
            }
            mask |= (1 << (ch-'a'));
        }
        partitions += 1;
        return partitions;
    }
};