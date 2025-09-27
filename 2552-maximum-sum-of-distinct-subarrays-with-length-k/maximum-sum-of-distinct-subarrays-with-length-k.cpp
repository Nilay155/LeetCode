class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,bool> mpp;

        int i = 0, j = 0;
        long long maxSum = 0, sum = 0;

        while(j < n) {
            sum += nums[j];

            while(j-i+1 > k && i < j) {
                sum -= nums[i];
                mpp.erase(nums[i]);
                i++;
            }
            while(mpp.find(nums[j]) != mpp.end() && i < j) {
                sum -= nums[i];
                mpp.erase(nums[i]);
                i++;
            }
            if(j-i+1 == k) maxSum = max(maxSum,sum);
            mpp.insert({nums[j],true});
            j++;
        }
        return maxSum;
    }
};