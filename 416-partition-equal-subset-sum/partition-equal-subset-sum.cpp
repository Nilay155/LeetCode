class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int num : nums) totalSum += num;
        
        if(totalSum%2 == 1) return false;
        
        int halfSum = (totalSum/2) + 1;
        vector<bool> dp(halfSum,false);
        dp[0] = true;

        for(int i = 0 ; i < n ; i++) {
            vector<bool> next(halfSum,false);

            for(int j = 1 ; j < halfSum ; j++) {
                if(nums[i] <= j) {
                    next[j] = next[j] | dp[j-nums[i]];
                }
            }
            for(int j = 0 ; j < halfSum ; j++) {
                next[j] = next[j] | dp[j];
            } 
            dp = next;
        }
        cout << halfSum << endl;
        return dp[halfSum-1];
    }
};