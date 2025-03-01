class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n-1 ; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        int cnt = 0;
        for(int num : nums) if(num == 0) cnt += 1;

        vector<int> ans;
        for(int num : nums) if(num != 0) ans.push_back(num);
        while(cnt--) {
            ans.push_back(0);
        }
        return ans;
    }
};