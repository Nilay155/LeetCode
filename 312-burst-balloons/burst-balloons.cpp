class Solution {
private:
    int dp[302][302];
    int f(vector<int> &nums,int i,int j) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MIN;

        for(int k = i ; k < j ; k++) {

            ans = max(ans,nums[i-1] * nums[j] * nums[k] 
                          + f(nums,i,k) + f(nums,k+1,j));
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int n = nums.size();

        memset(dp,-1,sizeof(dp));
        return f(nums,1,n-1);
    }
};