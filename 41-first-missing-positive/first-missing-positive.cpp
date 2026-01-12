class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int element = 0;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] >= 1 && nums[i] <= n) {
                element = nums[i];
                break;
            }
        }
        if(element == 0) return 1;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = element;
            }
        }

        for(int i = 0 ; i < n ; i++) {
            int index = abs(nums[i]);
            if(nums[index - 1] > 0) nums[index - 1] *= -1;
        }

        for(int i = 1; i <= n ; i++) {
            if(nums[i-1] > 0)
                return i;
        }
        return n+1;
    }
};