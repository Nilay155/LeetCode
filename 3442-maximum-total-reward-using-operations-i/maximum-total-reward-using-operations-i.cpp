class Solution {
private:
    int dp[2001][2001];
    int f(vector<int> &rewardValues,int i,int score,int &n) {

        if(i >= n)
            return 0;
        if(score >= 2000)
            return 0;
        if(dp[i][score] != -1) 
            return dp[i][score];
        
        int op1 = 0 + f(rewardValues,i + 1,score + 0,n);
        int op2 = 0;
        if(score < rewardValues[i])
            op2 = rewardValues[i] + f(rewardValues,i + 1,score + rewardValues[i],n);
        
        return dp[i][score] = max(op1,op2);
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        memset(dp,-1,sizeof(dp));
        return f(rewardValues,0,0,n);
    }
};