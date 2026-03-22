class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int s = 0, e = n - 1;
        while(s <= e) {
            int mid = (s + e) >> 1;
            bool k1 = (mid - 1) >= 0?(nums[mid] == nums[mid - 1]) ? true : false : false;
            bool k2 = (mid + 1) < n?(nums[mid] == nums[mid + 1]) ? true : false : false;

            if(k1 == false && k2 == false) return nums[mid];

            int l = k1 ? (mid - 2) : mid - 1;
            int r = k2 ? (mid + 2) : mid + 1;

            int leftRange = l + 1, rightRange = n - r;

            if(leftRange % 2 == 1) {
                if(k1) e = mid - 2;
                else e = mid - 1;
            } else {
                if(k2) s = mid + 2;
                else s = mid + 1;
            }
        }
        return -1;
    }
};