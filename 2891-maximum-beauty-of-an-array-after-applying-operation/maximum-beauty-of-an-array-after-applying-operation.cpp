class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        // Create ranges [nums[i] - k, nums[i] + k]
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i] - k, nums[i] + k});
        }

        // Sort ranges by their start points
        sort(arr.begin(), arr.end());

        // Sliding window to find maximum overlapping ranges
        int ans = 0;
        int cnt = 0;
        multiset<int> active;  // Store end points of active intervals

        for (int i = 0; i < n; i++) {
            int currStart = arr[i].first;
            int currEnd = arr[i].second;

            // Remove intervals that are no longer overlapping
            while (!active.empty() && *active.begin() < currStart) {
                active.erase(active.begin());
                cnt--;
            }

            // Add the current interval to the active set
            active.insert(currEnd);
            cnt++;

            // Update the maximum count
            ans = max(ans, cnt);
        }

        return ans;
    }
};
