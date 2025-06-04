class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> nums(n,1);

        for(int i = 1 ; i < n ; i++) {
            if(ratings[i] > ratings[i-1]) {
                nums[i] = 1 + nums[i-1];
            }
        }
        for(int i = n-2 ; i >= 0 ; i--) {
            if(ratings[i] > ratings[i+1]) {
                nums[i] = max(nums[i],1 + nums[i+1]);
            }
        }
        int ans = 0;
        for(int num : nums) ans += num;
        return ans;
    }
};