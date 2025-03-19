class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOperations = 0;

        for(int i = 0 ; i < n-2 ; i++) {

            if(nums[i] == 0) {
                for(int j = 0 ; j < 3 ; j++) {
                    nums[i+j] = 1 - nums[i+j];
                }
                minOperations++;
            }
        }

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 0) return -1;
        }
        return minOperations;
    }
};