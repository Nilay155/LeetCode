class Solution {
public:
    int maxFreeTime(int tt, vector<int>& st, vector<int>& et) {
        int n = st.size();

        vector<vector<int>> events;
        events.push_back({0,0});
        for(int i = 0 ; i < n ; i++) events.push_back({st[i],et[i]});
        events.push_back({tt,tt});
        
        vector<int> p(events.size()), s(events.size());
        for(int i = 1 ; i < events.size() - 1 ; i++) {
            p[i] = max(events[i][0] - events[i-1][1],p[i-1]);
        }
        for(int i = events.size()-2 ; i >= 1 ; i--) {
            s[i] = max(events[i+1][0] - events[i][1],s[i+1]);
        }
        // for(auto[g,c] : gaps) cout << g << "  " << c << "\n";

        int ans = 0;
        for(int i = 1 ; i < events.size()-1 ; i++) {
            int ls = events[i-1][0], le = events[i-1][1];
            int rs = events[i+1][0], re = events[i+1][1];
            int cs = events[i][0], ce = events[i][1];

            // trying to reschedule the current meeting to somewhere else
            // slide the block to some end
            ans = max(ans,rs - (le + (ce - cs)));

            // place somewhere between other blocks
            int suffix = s[i+1], prefix = p[i-1];
            if(suffix >= ce-cs || prefix >= ce-cs) ans = max(ans,rs - le);
            // taking the default time
            ans = max({ans,cs - le,rs - ce});
        }
        return ans;
    }
};