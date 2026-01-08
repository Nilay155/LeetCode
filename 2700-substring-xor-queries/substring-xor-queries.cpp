class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {
        int n = s.length(), m = q.size();

        unordered_map<string, pair<int,int>> mpp;

        for(int L = 1 ; L <= 32 ; L++) {
            int l = 0, r = 0;
            while(r < n) {
                
                if(r-l+1 >= L) {
                    string sub = s.substr(l,L);
                    // cout << sub << "  ";
                    if(mpp.find(sub) == mpp.end()) {
                        mpp[sub] = {l,r};
                    }
                    l += 1;
                }
                r += 1;
            }
            // cout << "\n";
        }
        vector<vector<int>> ans;
        for(int i = 0 ; i < m ; i++) {
            int f = q[i][0], s = q[i][1];
            int val = f ^ s;
            string str;
            if(val == 0) str.push_back('0');
            while(val) {
                int digit = val % 2;
                str += string(1,(digit + '0'));
                val /= 2;
            }
            reverse(str.begin(),str.end());
            if(mpp.find(str) != mpp.end()) {
                auto [li,ri] = mpp[str];
                ans.push_back({li,ri});
            } else {
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};