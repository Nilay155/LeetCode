class Solution {
private:
    vector<vector<int>> ans;

void f(vector<int> &s, int i, int &n) {
    if (i >= n) {
        ans.push_back(s);
        return;
    }

    unordered_set<int> used;

    for (int j = i; j < n; j++) {
        if (used.count(s[j])) continue;

        used.insert(s[j]);
        swap(s[i], s[j]);
        f(s, i + 1, n);
        swap(s[i], s[j]);
    }
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        f(nums, 0, n);
        return ans;
    }
};