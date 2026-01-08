class Solution {
public:
    int maxFreeTime(int tt, vector<int>& st, vector<int>& et) {
        int n = st.size();

        vector<vector<int>> events;
        events.push_back({0,0});
        for(int i = 0 ; i < n ; i++) events.push_back({st[i],et[i]});
        events.push_back({tt,tt});

        map<int,int> gaps;
        for(int i = 0 ; i < events.size() - 1 ; i++) {
            gaps[events[i+1][0] - events[i][1]] += 1;
        }
        // for(auto[g,c] : gaps) cout << g << "  " << c << "\n";
        gaps.erase(0);

        int ans = 0;
        for(int i = 1 ; i < events.size()-1 ; i++) {
            int ls = events[i-1][0], le = events[i-1][1];
            int rs = events[i+1][0], re = events[i+1][1];
            int cs = events[i][0], ce = events[i][1];

            // trying to reschedule the current meeting to somewhere else
            // slide the block to some end
            ans = max(ans,rs - (le + (ce - cs)));

            // place somewhere between other blocks
            int lg = cs - le, rg = rs - ce;
            auto it = gaps.lower_bound(ce-cs);
            int g = it -> first, c = it -> second;
            while(it != gaps.end() && !((g == lg && g == rg && c > 2) || (g == lg && g != rg && c > 1) || (g != lg && g == rg && c > 1) || (g != lg && g != rg && c > 0))) {
                it++;
                if(it != gaps.end()) {
                    g = it -> first, c = it -> second;
                }
            }
            if(it != gaps.end()) {
                ans = max(ans,rs - le);
            }
            // taking the default time
            ans = max({ans,cs - le,rs - ce});
        }
        return ans;
    }
};