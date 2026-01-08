class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        int sum = 0,ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i+1] > nums[i]) {
                sum += nums[i];
            } else {
                sum += nums[i];
                ans = max(ans,sum);
                sum = 0;
            }
        }
        sum = max(ans,sum);
        return ans;
    }
};