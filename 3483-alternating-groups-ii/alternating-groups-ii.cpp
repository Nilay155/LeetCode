class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int l = 0,r = 1, groups = 0;
        while(r < n) {
            // l -> indicates the start of the window
            // same numbers
            if(colors[r] == colors[r - 1]) {
                l = r;
            }
            if(r - l + 1 == k) {
                groups += 1;
                l += 1;
            }
            r += 1;
        }

        if(colors[n - 1] == colors[0])
            return groups;
        
        if(n - l + 1 == k)
            groups += 1, l += 1;

        r = 1;
        while(r < n && l < n) {

            if(colors[r] == colors[r - 1])
                break;
            
            if(r + (n - l) + 1 == k) {
                l += 1;
                groups += 1;
            }
            r += 1;
        }
        return groups;
    }
};