class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n,0);
        dp[n-1] = 1;

        for(int i = n-2 ; i >= 0 ; i--) {
            for(int j = i+1 ; j < n ; j++) {

                if((nums[j]%nums[i]) == 0) {
                    dp[i] = max(dp[i],1 + dp[j]);
                } else {
                    dp[i] = max(1,dp[i]);
                }
            }
        }

        int index = -1;
        int maxi = -1;

        for(int i = 0 ; i < n ; i++) {
            if(maxi < dp[i]) {
                maxi = dp[i];
                index = i;
            }
        }

        vector<int> res;
        res.push_back(nums[index]);
        maxi--;
        int lastElement = nums[index];

        for(int j = index+1 ; j < n ; j++) {
            if(dp[j] == maxi && nums[j]%lastElement == 0) {
                maxi--;
                lastElement = nums[j];
                res.push_back(nums[j]);
            }
        }
        return res;
    }
};