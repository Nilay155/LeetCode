class Solution {
public:
    int dp[50001][2];
    int f(vector<int> &prices,int &fee,int i,bool flag,int &n) {
        if(i >= n)
            return 0;
        if(dp[i][flag] != -1)
            return dp[i][flag];

        int ans = 0;
        if(flag) {
            // buy option is open
            ans = max(ans,-prices[i] + f(prices,fee,i + 1,false,n));
            ans = max(ans,f(prices,fee,i + 1,true,n));
        } else {
            // sell option is open
            ans = max(ans,prices[i] - fee + f(prices,fee,i + 1,true,n));
            ans = max(ans,f(prices,fee,i + 1,false,n));
        }
        return dp[i][flag] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int m = prices.size();
        memset(dp,-1,sizeof(dp));
        return f(prices,fee,0,true,m);
    }
};