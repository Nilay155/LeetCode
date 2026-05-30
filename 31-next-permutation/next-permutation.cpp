class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int index = -1;
        for(int i = n - 2 ; i >= 0 ; i--) {
            if(nums[i] < nums[i + 1]) {
                // desc order broken
                index = i;
                break;
            }
        }
        if(index == -1) {
            reverse(nums.begin(),nums.end());
            return ;
        }

        // finding the nextgreater element than nums[i]
        int nge = -1;
        for(int i = index + 1 ; i < n ; i++) {
            if(nums[i] > nums[index]) nge = i;
        }
        swap(nums[index],nums[nge]);

        reverse(nums.begin() + index + 1,nums.end());
        return ;
    }
};