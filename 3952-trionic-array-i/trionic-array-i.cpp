class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int p = -1, q = -1;
        for(int i = 1 ; i < n ; i++) {
            if(nums[i-1] > nums[i]) {
                p = i-1;
                break;
            } else if(nums[i-1] == nums[i]) return false;
        }
        if(p == 0 || p == -1) return false;
        for(int i = p+1 ; i < n ; i++) {
            if(nums[i-1] < nums[i]) {
                q = i-1;
                break;
            } else if(nums[i-1] == nums[i]) return false;
        }
        if(q == -1 || q == n-1) return false;
        for(int i = q+1 ; i < n ; i++) {
            if(nums[i-1] >= nums[i]) return false;
        }
        // cout << p << "  " << q << "\n";
        return true;
    }
};