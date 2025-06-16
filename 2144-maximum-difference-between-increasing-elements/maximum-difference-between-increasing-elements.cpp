class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        int maxDiff = -1;
        int maxi = nums[n-1];

        for(int i = n-2 ; i >= 0 ; i--) {
            if(maxi > nums[i]) {
                maxDiff = max(maxDiff,maxi-nums[i]);
            }
            maxi = max(maxi,nums[i]);
        }
        return maxDiff;
    }
};