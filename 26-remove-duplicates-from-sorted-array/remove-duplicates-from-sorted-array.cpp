class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        while(j < n) {
            nums[i] = nums[j];
            i += 1, j += 1;
            while(j > 0 && j < n && nums[j] == nums[j - 1]) j++;
        }
        return i;
    }
};