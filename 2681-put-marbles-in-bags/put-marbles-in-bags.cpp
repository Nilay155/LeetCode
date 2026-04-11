typedef long long ll;
class Solution {
private:
    ll f(vector<int> &w,int k) {
        int n = w.size();

        vector<vector<ll>> dp(k,vector<ll> (n,0));
        for(int i = 0 ; i < n ; i++) {
            dp[0][i] = w[0] + w[i];
        }

        for(int K = 1 ; K < k ; K += 1) {
            for(int i = K ; i < n ; i += 1) {

                // If I Break at index i
                ll prev = dp[K - 1][i - 1];
                ll curr = w[i] + w[n - 1]; // the remaining subarray
                dp[K][i] = prev + curr;
            }
        }
        ll maxi = -1e18,mini = 1e18;
        for(int i = k - 1 ; i < n ; i++) {
            mini = min(mini,dp[k - 1][i]);
            maxi = max(maxi,dp[k - 1][i]);
        }
        return maxi - mini;
    }
public:
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        // O(n*n*k) -> DP is not a feasable solution
        if(k == 1) return 0;

        vector<ll> partitionSums;
        for(int i = 0 ; i < n - 1 ; i++) 
            partitionSums.push_back(w[i] + w[i + 1]);
        
        sort(partitionSums.begin(),partitionSums.end());
        ll mini = 0;
        for(int i = 0 ; i < k - 1 ; i++) {
            mini += partitionSums[i];
        }
        reverse(partitionSums.begin(),partitionSums.end());
        ll maxi = 0;
        for(int i = 0 ; i < k - 1 ; i++) {
            maxi += partitionSums[i];
        }
        return maxi - mini;
    }
};