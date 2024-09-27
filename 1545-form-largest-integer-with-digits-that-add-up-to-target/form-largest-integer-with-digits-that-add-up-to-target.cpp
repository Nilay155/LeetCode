class Solution {
public:
    string solve(vector<int> &cost,int val,int &k,unordered_map<int,string> &dp) {
        if(val > k) return "0";
        if(val == k) return "";

        if(dp.count(val) > 0) return dp[val];
        
        string res = "0",ans;

        for(int i = 1 ; i <= 9 ; i++) {
            ans = solve(cost,val + cost[i-1],k,dp);
        
            if(ans == "0") continue;

            ans = to_string(i) + ans;
            if(ans.size() >= res.size()) res = ans;
        }
        dp[val] = res;
        return res;
    }
    string largestNumber(vector<int>& cost, int target) {
        unordered_map<int,string> dp;
        return solve(cost,0,target,dp);
    }
};