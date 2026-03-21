class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;

        while(s <= e) {

            int mid = (s + e) >> 1;

            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] >= nums[0]) { // left-space

                if(nums[s] <= target && target <= nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else { // right-space

                if(nums[mid] <= target && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};