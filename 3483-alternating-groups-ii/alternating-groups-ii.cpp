class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;

        int l = 0, r = 0;
        while(r < n) {
            // Counting valid windows
            if(r-l+1 == k) {
                ans += 1;
                l += 1;
            }

            // Window Handling
            if(r+1 < n) {
                if(colors[r] != colors[r+1]) {
                    r += 1;
                } else {
                    r += 1;
                    l = r;
                }
            } else {
                break;
            }
        }

        // circular pattern
        while(l < n) {
            if(n-l+((r+1)%n) == k) {
                ans += 1;
                l += 1;
            }

            if(colors[r%n] != colors[(r+1)%n]) {
                r += 1;
            } else {
                break;
            }
        }
        return ans;
    }
};