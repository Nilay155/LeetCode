class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> one, two;
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 3 == 1) one.push(nums[i]);
            else if (nums[i] % 3 == 2) two.push(nums[i]);
            totalSum += nums[i];
        }

        if (totalSum % 3 == 0) return totalSum;
        else if (totalSum % 3 == 1) {
            // Remove one number from 'one' or two numbers from 'two'
            int removeOne = INT_MAX, removeTwo = INT_MAX;
            if (!one.empty()) removeOne = one.top();
            if (two.size() >= 2) {
                int first = two.top(); two.pop();
                int second = two.top();
                removeTwo = first + second;
            }
            if (removeOne == INT_MAX && removeTwo == INT_MAX) return 0;
            return totalSum - min(removeOne, removeTwo);
        } else {
            // Remove one number from 'two' or two numbers from 'one'
            int removeTwo = INT_MAX, removeOnePair = INT_MAX;
            if (!two.empty()) removeTwo = two.top();
            if (one.size() >= 2) {
                int first = one.top(); one.pop();
                int second = one.top();
                removeOnePair = first + second;
            }
            if (removeTwo == INT_MAX && removeOnePair == INT_MAX) return 0;
            return totalSum - min(removeTwo, removeOnePair);
        }
    }
};
