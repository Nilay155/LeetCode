class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int s = intervals[0][0], e = intervals[0][1];
        // cout << s << " : " << e << "\n";
        int ans = 0, i = 1;
        while(i < n) {
            int ns = intervals[i][0], ne = intervals[i][1];
            // cout << ns << " : " << ne << "\n";
            if(ns < e) { // overlapping
                if(e > ne) { // current_end > next_end
                    s = ns, e = ne;
                }
                ans += 1;
            } else { // non-overlapping
                s = ns, e = ne;
            }
            i += 1;
        }
        return ans;
    }
};