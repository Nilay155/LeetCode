class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        int n = colors.size();
        int alternatingGroups = 0;
        int pairs = k-1;

        int count = 0;
        int lastElement = colors[0];
        for(int i = 1 ; i < n; i++) {
        
            count += (colors[i] != lastElement) ? 1 : (-count);
            if(count >= pairs) alternatingGroups += 1;
            lastElement = colors[i];
        }

        for(int i = 0 ; i < k-1 ; i++) {
            count += (colors[i] != lastElement) ? 1 : (-count);
            if(count >= pairs) alternatingGroups += 1;
            lastElement = colors[i];
        }
        return alternatingGroups;
    }
};