class Solution {
private:
    int dp[20001];
    unordered_map<int,int> count;
    int f(vector<pair<int,int>> &nums,int i,int &n) {

        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int op1 = f(nums,i + 1,n);
        int op2 = 0;
        int next = nums[i].first + 1;
        if(count.count(next)) {
            op2 = nums[i].first* nums[i].second + f(nums, i + 2,n);
        } else {
            op2 = nums[i].first* nums[i].second + f(nums, i + 1,n);
        }
        return dp[i] = max(op1,op2);
    } 
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        count.clear();
        for(int e : nums) count[e] += 1;

        vector<pair<int,int>> arr;
        for(auto [e,c] : count) {
            arr.push_back({e,c});
        }
        int m = arr.size();
        sort(arr.begin(),arr.end());
        // memset(dp,-1,sizeof(dp));
        // return f(arr,0,m);
        vector<int> dp(m,0);
        dp[0] = arr[0].first * arr[0].second;
        for(int i = 1 ; i < m ; i++) {
            int e = arr[i].first, c = arr[i].second;
            // left
            int le = arr[i - 1].first;
            int res = e * c;
            if(le + 1 != e) {
                res += dp[i - 1];
            } else {
                res += ((i - 2 >= 0 ? dp[i - 2] : 0));
            }
            dp[i] = max(res,dp[i - 1]);
        }
        return dp[m - 1];
    }
};