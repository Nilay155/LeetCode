class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());

        vector<vector<int>> mergedIntervals;
        int s = meetings[0][0], e = meetings[0][1];
        for(int i = 1 ; i < n ; i++) {
            int ns = meetings[i][0], ne = meetings[i][1];

            if(ns <= e) {
                // overlapping intervals
                s = min(s,ns);
                e = max(e,ne);
            } else {
                mergedIntervals.push_back({s,e});
                s = ns,e = ne;
            }
        }
        mergedIntervals.push_back({s,e});
        n = mergedIntervals.size();
        int freeDays = 0;
        freeDays += mergedIntervals[0][0] - 1;
        for(int i = 1 ; i < n ; i++) {
            freeDays += (mergedIntervals[i][0] - mergedIntervals[i-1][1] - 1);
        }
        freeDays += (days - mergedIntervals[n-1][1]);
        return freeDays;
    }
};