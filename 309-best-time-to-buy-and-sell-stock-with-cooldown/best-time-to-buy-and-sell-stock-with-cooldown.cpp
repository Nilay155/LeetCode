class Solution {
private:
    int dp[5001][2];
    int f(vector<int> &prices,int i,bool buy,int &n) {
        if(i >= n)
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int ans = 0;
        if(buy) {
            int rec1 = -prices[i] + f(prices,i + 1,false,n);
            int rec2 = f(prices,i + 1,true,n);
            ans = max(ans,max(rec1,rec2));
        } else {
            int rec1 = prices[i] + f(prices,i + 2,true,n);
            int rec2 = f(prices,i + 1,false,n);
            ans = max(ans,max(rec1,rec2));
        }
        return dp[i][buy] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return f(prices,0,true,n);
    }
};