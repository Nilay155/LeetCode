class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;

        while(j < n) {
            int count = 1;
            while(j + 1 < n && nums[j] == nums[j + 1])
                count += 1, j += 1;
            
            int limit = min(2,count);
            while(limit--) nums[i++] = nums[j];
            j += 1;
        }
        return i;
    }
};