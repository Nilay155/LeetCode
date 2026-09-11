class Solution {
private:
    int dp[8][16385];
    long long f(vector<int> &nums,int i,int &n,int mask) {
        if(i > n)
            return 0;
        if(dp[i][mask] != -1)
            return dp[i][mask];

        int m = nums.size();
        long long ans = 0;

        for(int u = 0 ; u < m ; u++) {
            for(int v = u + 1 ; v < m ; v++) {
                if (!(mask & (1 << u)) && !(mask & (1 << v))) {
                    mask |= (1 << u);
                    mask |= (1 << v);

                    ans = max(ans,
                        (long long)i * __gcd(nums[u], nums[v]) +
                        f(nums, i + 1, n, mask)
                    );
                    mask &= ~(1 << u);
                    mask &= ~(1 << v);
                }
            }
        }
        return dp[i][mask] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        int k = n/2;
        memset(dp,-1,sizeof(dp));
        return f(nums,1,k,0);
    }
};