class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int move = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] < 0) move += nums[i];
            else move += nums[i];

            if(move == 0) ans += 1;
        }
        return ans;
    }
};