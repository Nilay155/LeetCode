class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),[&](vector<int> &A,vector<int> &B) {
            if(A[0] == B[0])
                return A[1] < B[1];
            return A[0] < B[0];
        });

        vector<int> dp(n,1);
        for(int i = 1 ; i < n ; i++) {
            for(int j = i - 1 ; j >= 0 ; j--) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i],1 + dp[j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            ans = max(ans,dp[i]);
            // cout << pairs[i][0] << " : " << pairs[i][1] << "\n";
        }
        return ans;
    }
};