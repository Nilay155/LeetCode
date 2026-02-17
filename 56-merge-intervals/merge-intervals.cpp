class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> mergeIntervals;
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1 ; i < n ; i++) {
            int ns = intervals[i][0], ne = intervals[i][1];
            if(ns <= e) {
                s = min(s,ns), e = max(ne,e);
            } else {
                mergeIntervals.push_back({s,e});
                s = ns, e = ne;
            }
        }  
        mergeIntervals.push_back({s,e});
        return mergeIntervals;
    }
};