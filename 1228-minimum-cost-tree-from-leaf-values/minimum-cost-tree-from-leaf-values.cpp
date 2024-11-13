class Solution {
    int findMax(vector<int> &nums,int l,int r) {
        int maxi = 0;
        for(int k = l ; k <= r ; k++) maxi = max(maxi,nums[k]);
        return maxi;
    }
public:
    int dp[41][41];
    int solve(vector<int> &nums,int left,int right) {
        if(left >= right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int res = INT_MAX;
        for(int k = left ; k < right ; k++) {
            int leftMax = findMax(nums,left,k);
            int rightMax = findMax(nums,k+1,right);
            int nodeValue = leftMax*rightMax;
            res = min(res,nodeValue + solve(nums,left,k) + solve(nums,k+1,right));
        }
        return dp[left][right] = res;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,n-1);
    }
};