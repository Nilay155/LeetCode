class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = pow(2,n)-1; 
        vector<vector<int>> ans;
        for(int k = 0 ; k <= subsets ; k++) {
            int num = k, z = n-1;
            vector<int> dp(n,0);
            while(num) {
                dp[z--] = num%2;
                num /= 2;
            }
            vector<int> temp;
            for(int i = 0 ; i < n ; i++) {
                if(dp[i]) temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};