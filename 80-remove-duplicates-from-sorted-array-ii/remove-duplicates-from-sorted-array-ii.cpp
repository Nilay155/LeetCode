class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;

        while(r < n) {
            int cnt = 1, ele = nums[r];
            while(r+1 < n && nums[r] == nums[r+1]) {
                cnt = 2;
                r += 1;
            }
            while(cnt--) {
                nums[l] = ele;
                l += 1;
            }
            r += 1;
        }
        return l;
    }
};