class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();

        int li = bounds[0][0], hi = bounds[0][1];
        int ans = INT_MAX;
        for(int i = 1 ; i < n ; i++) {
            int diff = original[i] - original[i-1];

            int newLi = li + diff, newHi = hi + diff;
            int currLi = bounds[i][0], currHi = bounds[i][1];
            if((currLi >= newLi && currLi <= newHi) || (newLi >= currLi && newLi <= currHi)) {
                li = max(newLi,currLi);
                hi = min(newHi,currHi);
            } else {
                ans = 0;
            }
        }
        return ans == INT_MAX ? hi - li + 1 : ans;
    }
};