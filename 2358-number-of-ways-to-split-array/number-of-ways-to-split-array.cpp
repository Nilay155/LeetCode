class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int validPoints = 0;

        long long int totalSum = 0;
        for(int num : nums) totalSum += num;

        long long int currSum = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            currSum += nums[i];
            long long int remSum = totalSum - currSum;

            if(currSum >= remSum) {
                validPoints += 1;
            }
        }
        return validPoints;
    }
};