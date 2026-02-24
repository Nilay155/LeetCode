class SummaryRanges {
private:
    vector<vector<int>> intervals;
    unordered_map<int,bool> vis;
public:
    SummaryRanges() {
        intervals.clear();
        vis.clear();
    }
    
    void addNum(int value) {
        if(vis.find(value) != vis.end()) return ;
        vis.insert({value,true});
        // one point to remeber is intervals array is of sorted non-overlapping intervals
        int n = intervals.size();
        if(n == 0) {
            intervals.push_back({value,value});
            return ;
        }
        int idx = -1;
        for(int i = 0 ; i < n ; i++) {
            int s = intervals[i][0], e = intervals[i][1];
            if(s > value) {
                break;
            }
            idx = i;
        }
        if(idx == -1) {
            if(intervals[0][0] > value) intervals.insert(intervals.begin(),{value,value});
            else intervals.push_back({value,value});
        } else {
            intervals.insert(intervals.begin() + idx + 1,{value,value});
        }

        n = intervals.size();
        vector<vector<int>> newIntervals;
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1 ; i < n ; i++) {
            int ns = intervals[i][0], ne = intervals[i][1];

            if(ns <= e+1) {
                s = min(s,ns);
                e = max(e,ne);
            } else {
                newIntervals.push_back({s,e});
                s = ns, e = ne;
            }
        }
        newIntervals.push_back({s,e});
        intervals = newIntervals;
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */