class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.length();
        vector<int> lastPositions(26,n);
        vector<vector<int>> indexes(26);
        for(int i = 0 ; i < n ; i++) {
            lastPositions[s[i] - 'a'] = i;
            indexes[s[i] - 'a'].push_back(i);
        }

        vector<pair<int,int>> positions;
        for(int i = 0 ; i < 26 ; i++) {
            if(lastPositions[i] != n) {
                positions.push_back({lastPositions[i],i});
            }
            indexes[i].push_back(n);
        }
        sort(positions.begin(),positions.end());
        vector<int> order(26,0);

        int m = positions.size(), o = 1, prev = -1;

        for(int i = 0 ; i < m ; i++) {
            auto [pos,ch] = positions[i];
            if(order[ch] != 0) continue;
            for(int j = 0 ; j < ch ; j++) {
                if(order[j] == 0) {
                    // hasn't yet occured in the answer
                    auto it = upper_bound(indexes[j].begin(), indexes[j].end(), prev);

                    if (it != indexes[j].end()) {
                        int k = *it;
                        if (k < pos) {
                            // cout << prev << " : " << k << " : " << pos << "\n";
                            order[j] = o++;
                            prev = k;
                        }
                    }
                }
            }

            auto it = upper_bound(indexes[ch].begin(), indexes[ch].end(), prev);
            int k = *it;
            if (k <= pos) {
                // cout << prev << " : " << k << " : " << pos << "\n";
                order[ch] = o++;
                prev = k;
            }
        }
        vector<pair<int,int>> res;
        for(int i =  0 ; i < 26 ; i++) {
            if(order[i] != 0) {
                res.push_back({order[i],i});
            }
        }
        sort(res.begin(),res.end());
        string ans;
        for(int i = 0 ; i < (int) res.size() ; i++) {
            ans.push_back(res[i].second + 'a');
        }
        return ans;

    }
};