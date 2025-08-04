class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int jumpDistance = nums[0];

        for(int i = 1 ; i < n ; i++) {
            if(jumpDistance == 0) return false;
            jumpDistance = max(jumpDistance-1,nums[i]);
            if(i + jumpDistance >= n-1) return true;
        }
        return false;
    }
};