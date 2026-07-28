class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length = 1, ans = 1, n = nums.size();
        bool prev = true;

        for(int i = 1 ; i < n ; i++) {

            if(nums[i - 1] > nums[i]) {
                if(prev) {
                    prev = !prev;
                    ans = max(ans,length);
                    length = 1;
                }
                length += 1;
            } else if(nums[i - 1] < nums[i]) {
                if(!prev) {
                    prev = !prev;
                    ans = max(ans,length);
                    length = 1;
                }
                length += 1;
            } else {
                ans = max(ans,length);
                length = 1;
            }
        }
        ans = max(ans,length);
        return ans;
    }
};