class Solution {
private:
    int count[10001];
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(count,0,sizeof(count));

        for(int num : nums) count[num]++;
        vector<int> arr;
        for(int i = 1 ; i < 10001 ; i++) 
            if(count[i] > 0) 
                arr.push_back(i);
        
        int n = arr.size();
        vector<int> dp(n,0);
        
        dp[0] = arr[0] * count[arr[0]];

        if(n > 1 && arr[0]+1 == arr[1]) dp[1] = arr[1] * count[arr[1]];
        else if(n > 1) dp[1] = arr[1] * count[arr[1]] + dp[0];
        if(n > 1) dp[1] = max(dp[1],dp[0]);

        for(int i = 2 ; i < n ; i++) {
            int prev = arr[i-1];
            int val = 0;
            if(prev+1 != arr[i]) val = dp[i-1];
            dp[i] = max({arr[i] * count[arr[i]] + dp[i-2],arr[i] * count[arr[i]] + val,dp[i-1]});
        }
        
        return dp[n-1];
    }
};