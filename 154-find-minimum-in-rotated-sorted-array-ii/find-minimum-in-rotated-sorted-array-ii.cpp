class Solution {
public:
    int findMin(vector<int>& nums) {
        // O(n) -> return min_element
        // O(logn) -> with duplicates
        int n = nums.size();
        if(n == 1) return nums[0];

        int s = 0, e = n - 1;

        while(s < e) {
            int mid = s + (e - s) / 2;

            if(nums[mid] > nums[mid + 1]) 
                return nums[mid + 1];
            
            while(e > mid && nums[mid] == nums[e]) e--;

            if(nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }

        }
        if(nums[0] <= nums[1]) return nums[0];
        if(nums[n-1] <= nums[n-2]) return nums[n-1];
        return -1;
    }
};