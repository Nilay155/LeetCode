class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int s = 0, e = n - 1;
        while(s < e) {
            int mid = s + (e - s) / 2;
            if(nums[s] <= nums[mid]) {
                // left-space
                if(nums[mid] > nums[e]) {
                    // left-Partition
                    s = mid + 1;
                } else {
                    // right - partition
                    e = mid - 1;
                }
            } else { 
                // right-space
                e = mid;
            }
        }
        cout << s << "  :  " << e << "\n"; 
        return nums[s];
    }
};