class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, r = 0;
        double avg = 0, maxi = -1e9 - 7;

        while(r < n) {
            avg += nums[r];
            if(r - l + 1 == k) {
                maxi = max(maxi, avg / (double)k);
                avg -= nums[l];
                l += 1;
            }
            r += 1;
        }
        return maxi;
    }
};