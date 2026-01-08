class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, pair<int,int>> mp;   // val -> {l, r}
        int n = s.size();

        // Precompute all substrings of length <= 31
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                // single zero substring always has value 0
                if (!mp.count(0)) mp[0] = {i, i};
                continue;
            }

            long long val = 0;
            for (int j = i; j < n && j < i + 31; j++) {
                val = (val << 1) | (s[j] - '0');
                if (!mp.count(val)) mp[val] = {i, j};
            }
        }

        vector<vector<int>> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            long long target = (long long)q[0] ^ q[1];
            if (mp.count(target)) {
                ans.push_back({mp[target].first, mp[target].second});
            } else {
                ans.push_back({-1, -1});
            }
        }

        return ans;
    }
};