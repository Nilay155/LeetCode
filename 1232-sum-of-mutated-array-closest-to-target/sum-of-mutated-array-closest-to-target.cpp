class Solution {
public:
    int findBestValue(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int limit = nums[n - 1];
        vector<int> prefixSum(n,0);
        
        prefixSum[0] = nums[0];
        for(int i = 1 ; i < n ; i++) prefixSum[i] = nums[i] + prefixSum[i - 1];

        int ans = INT_MAX, diff = INT_MAX;
        for(int k = 0 ; k <= limit ; k++) {

            int index = upper_bound(nums.begin(),nums.end(),k) - nums.begin();
            
            int newSum = (index - 1 >= 0) ? prefixSum[index - 1] : 0;
            newSum += (n - index) * k;

            if(abs(target - newSum) < diff) {
                diff = abs(target - newSum);
                ans = k;
            }
        }
        return ans;
    }
};