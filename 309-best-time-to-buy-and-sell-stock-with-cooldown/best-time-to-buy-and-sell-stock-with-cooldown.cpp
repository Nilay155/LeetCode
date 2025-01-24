class Solution {
public:
    int func(vector<int> &prices,int i,bool buying,int &n) {
        if(i >= n) return 0;

        int buy = 0, cool1 = 0, cool2 = 0, sell = 0;
        if(buying) {
            buy = -prices[i] + func(prices,i+1,!buying,n);
            cool1 = 0 + func(prices,i+1,buying,n);
        } else {
            sell = prices[i] + func(prices,i+2,!buying,n);
            cool2 = 0 + func(prices,i+1,buying,n);
        }
        return max({buy,cool1,cool2,sell});
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int i = n-1 ; i >= 0 ; i--) {
            for(int buying = 1 ; buying >= 0 ; buying--) {
                int buy = 0, cool1 = 0, cool2 = 0, sell = 0;
                if(buying) {
                    buy = -prices[i] + dp[i+1][0];
                    cool1 = 0 + dp[i+1][buying];
                } else {
                    sell = prices[i] + dp[i+2][1];
                    cool2 = 0 + dp[i+1][buying];
                }
                dp[i][buying] = max({buy,cool1,cool2,sell});
            }
        }
        return dp[0][1];
        // return func(prices,0,true,n);
    }
};