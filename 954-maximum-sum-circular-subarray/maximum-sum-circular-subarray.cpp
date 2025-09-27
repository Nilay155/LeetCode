class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int totalSum = 0;
        for(int num : nums) totalSum += num;

        int minSum = 0, sum = 0;
        for(int num : nums) {
            sum += num;
            if(sum < 0) {
                minSum = min(minSum,sum);
            } else {
                sum = 0;
            }
        }

        int maxSum = INT_MIN;
        sum = 0;
        for(int num : nums) {
            sum += num;

            if(sum > 0) {
                maxSum = max(maxSum,sum);
            } else {
                maxSum = max(sum,maxSum);
                sum = 0;
            }
        }

        if(totalSum == minSum) return maxSum;
        else return max(maxSum,totalSum - minSum);
    }
};