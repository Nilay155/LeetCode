class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int minOperations = 0;
        for(int i = 1 ; i < n ; i++) {

            if(nums[i - 1] >= nums[i]) {
                int ops = (nums[i - 1] - nums[i] + 1);
                nums[i] += ops;
                minOperations += ops;
            }
        }
        return minOperations;
    }
};