class Solution {
public:
    int maxVal(vector<int> &arr,int i,int j) {
        int maxi = -1e9;
        for(int k = i ; k <= j ; k++) {
            maxi = max(maxi,arr[k]);
        }
        return maxi;
    }
    int solve(vector<int> &arr,int &k,int i,int &n) {
        if(i >= n) return 0;

        int ans = 0;

        for(int j = i ; j < n ; j++) {
            if(j-i+1 <= k) {
                // Valid Partition
                ans = max(ans,maxVal(arr,i,j)*(j-i+1) + solve(arr,k,j+1,n));
            }
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // return solve(arr,k,0,n);
        vector<int> dp(n+1,0);
        for(int i = n-1 ; i >= 0 ; i--) {
            int temp = 0;
            int maxi = -1e9;
            for(int j = i ; j < n ; j++) {
                if(j-i+1 <= k) {
                    maxi = max(maxi,arr[j]);
                    temp = max(temp,maxi*(j-i+1) + dp[j+1]);
                }
            }
            dp[i] = temp;
        }
        return dp[0];
    }
};