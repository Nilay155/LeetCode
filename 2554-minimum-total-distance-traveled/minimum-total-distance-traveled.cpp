typedef long long ll;
class Solution {
private:
    vector<vector<ll>> dp;
    ll f(vector<int> &r,vector<int> &nums,int i,int j) {

        if(i >= r.size()) return 0;
        if(j >= nums.size()) return 1e18;

        if(dp[i][j] != -1) 
            return dp[i][j];

        ll minCost = f(r,nums,i,j + 1);
        ll distance = llabs(r[i] - nums[j]);

        minCost = min(minCost,distance + f(r,nums,i + 1,j + 1));
        return dp[i][j] = minCost;
    }
public:
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& ff) {
        int n = r.size(), m = ff.size();
        sort(r.begin(),r.end());

        vector<int> nums;
        for(int i = 0 ; i < m ; i++) 
            for(int j = 0 ; j < ff[i][1] ; j++)
                nums.push_back(ff[i][0]);
        
        sort(nums.begin(),nums.end());
        m = nums.size();
        // for(int f : nums) cout << f << "   ";
        dp = vector<vector<ll>>(n,vector<ll>(m,-1));
        return f(r,nums,0,0);
    }
};