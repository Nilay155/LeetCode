class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());

        int prefix = 1, ans = 0;
        for(int i = 1 ; i < n ; i++) {

            if(nums[i] != nums[i-1]) {
                ans += prefix;
            }
            prefix += 1;
        }
        return ans;
    }
};