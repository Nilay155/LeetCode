class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,0);
        for(int i = 0 ; i < n ; i++) {
            double num = sqrt(nums[i]);

            int start = 0;
            int end = n-1;
            int res = -1;

            while(start <= end) {
                int mid = (start + end) >> 1;

                if(double(nums[mid]) == num) {
                    res = mid;
                    break;
                } else if(double(nums[mid]) > num) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            if(res == -1) continue;
            else dp[i] = 1 + dp[res];
        }
        int ans = -1;
        for(int i = 0 ; i < n ; i++) {
            if(dp[i] != 0) ans = max(ans,1 + dp[i]);
        }
        return ans;
    }
};