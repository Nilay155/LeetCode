class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        if(n == 1) return nums[0];

        while(s < e) {
            int mid = s + (e - s) / 2;

            if(nums[mid] > nums[mid + 1]) 
                return nums[mid + 1];
            
            if(nums[mid] >= nums[e]) { 
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        
        if(nums[0] < nums[1]) return nums[0];
        if(nums[n - 1] < nums[n - 2]) return nums[n - 1];
        return -1;
    }
};