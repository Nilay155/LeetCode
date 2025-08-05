class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        for(auto interval : intervals) {
            cout << interval[0] << " : " << interval[1] << endl;
        }

        int res = 0, count = 0;
        int start = intervals[0][0], end = intervals[0][1];

        for(int i = 1 ; i < n ; i++) {

            if(intervals[i][0] < end) {
                count++;
                end = min(end,intervals[i][1]);
            } else {
                res += count;
                count = 0;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res += count;
        return res;
    }
};