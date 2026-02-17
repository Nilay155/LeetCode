class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};
        int ns = newInterval[0], ne = newInterval[1];

        if(intervals[0][0] > ne) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if(intervals[n-1][1] < ns) {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> ans;
        int i = 0;
        while(i < n && ns > intervals[i][1]) {
            ans.push_back(intervals[i]);
            i += 1;
        }

        // if i < n means overlapping with an interval is found
        int s = intervals[i][0], e = intervals[i][1];
        if((ns >= s || (ne >= s && ne <= e)) || (e >= ns && e <= ne)) { // check if these two intervals in case are overlapping
            // case -> 1,2,3
            // cout << i << "\n";
            s = min(s,ns), e = max(e,ne);
            i += 1;
            while(i < n) {
                int ss = intervals[i][0], ee = intervals[i][1];
                if(ss <= e) {
                    s = min(ss,s);
                    e = max(e,ee);
                } else {
                    ans.push_back({s,e});
                    s = ss, e = ee;
                }
                i += 1;
            }
            ans.push_back({s,e});
        } else{
            ans.push_back({ns,ne});
        }
    
        while(i < n) {
            ans.push_back(intervals[i]);
            i += 1;
        }
        return ans;
    }
};