class Solution {
private:
    unordered_map<int,int> vis;
    int dp[2001][2001];
    bool f(vector<int> &stones,int i,int k,int &n) {
        if(i >= n-1)
            return true;
        if(k <= 0)
            return false;
        // if(dp.find(i) != dp.end() && dp[i].find(k) != dp[i].end())
        //     return dp[i][k];
        if(dp[i][k] != -1)
            return dp[i][k];

        int jump1 = stones[i] + k, 
            jump2 = stones[i] + k - 1,
            jump3 = stones[i] + k + 1;

        bool ans = false;
        if(vis.find(jump1) != vis.end()) {
            int j = vis[jump1];
            ans = ans | f(stones,j,k,n);
        } 
        if(vis.find(jump2) != vis.end()) {
            int j = vis[jump2];
            ans = ans | f(stones,j,k - 1,n);
        }
        if(vis.find(jump3) != vis.end()) {
            int j = vis[jump3];
            ans = ans | f(stones,j,k + 1,n);
        }
        return dp[i][k] = ans;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int i = 1;
        // stones[0] == 0
        if(stones[1] > 1) 
            return false;
        
        vis.clear();
        for(int i = 2 ; i < n ; i++) 
            vis[stones[i]] = i;
        memset(dp,-1,sizeof(dp));
        return f(stones,i,1,n);
    }
};