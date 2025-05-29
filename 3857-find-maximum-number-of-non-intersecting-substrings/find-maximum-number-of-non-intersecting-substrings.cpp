class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<pair<int, int>> valid;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 3; j < n; ++j) {
                if (word[i] == word[j]) {
                    valid.emplace_back(i, j);
                    break;
                }
            }
        }

        sort(valid.begin(), valid.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        int count = 0, lastEnd = -1;

        for (auto [start, end] : valid) {
            if (start > lastEnd) {
                count++;
                lastEnd = end;
            }
        }

        return count;
    }
};