class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) {
            int ele = abs(nums[i]);
            if(nums[ele - 1] < 0)
                ans.push_back(ele);
            nums[ele - 1] *= -1;
        }
        return ans;
    }
};