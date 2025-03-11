class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return {};

        vector<int> res;
        deque<int> dq;

        for(int i = 0 ; i < k ; i++) {
            if(dq.empty()) dq.push_back(i);
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for(int i = k ; i < n ; i++) {
            while(!dq.empty() && i-dq.front() >= k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};