class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1, prev = 1;
        for(int i = 2 ; i <= n ; i++) {
            ans = (ans +  4LL * prev);
            prev += 1;
        }
        return ans;
    }
};