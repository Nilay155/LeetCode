class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;

        vector<int> ans(n - k + 1, -1);
        int u = 0;
        for(int i = 0 ; i < k ; i++) {
            while(!dq.empty() && nums[dq.front()] <= nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
        }
        ans[u++] = nums[dq.back()];

        for(int i = k ; i < n ; i++) {
            while(!dq.empty() && i - k >= dq.back()) {
                dq.pop_back();
            }
            while(!dq.empty() && nums[dq.front()] <= nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
            ans[u++] = nums[dq.back()];
        }
        return ans;
    }
};