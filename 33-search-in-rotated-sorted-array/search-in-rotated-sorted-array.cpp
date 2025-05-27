class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int s = 0, e = n-1, x = target;

        while(s <= e) {
            int mid = (s + e) >> 1;
            // cout << s << " " << e << " " << mid << endl;
            if(nums[mid] == x) return mid;

            if(nums[mid] >= nums[s]) {
                if(nums[s] <= x && x < nums[mid]) e = mid-1;
                else s = mid+1;
            } else {
                if(nums[e] >= x && nums[mid] < x) s = mid+1;
                else e = mid-1;
            }
        }
        return -1;
    }
};