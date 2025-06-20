class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int ans = 0;

        int i = 0, j = 0;

        while(j < n) {
            
            if(nums[j]-nums[i] <= k) {
                j += 1;
            } else {
                ans += 1;
                i = j;
            }
        }

        if(nums[j-1]-nums[i >= n ? i-1 : i] <= k) ans += 1;
        return ans;
    }
};