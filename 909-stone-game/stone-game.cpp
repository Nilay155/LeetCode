class Solution {
public:
    int dp[501][501][2];
    int solve(vector<int> &piles,int left,int right,int turn) {
        if(left >= right) return (turn == 1) ? piles[left] : -piles[right];
        if(dp[left][right][turn] != -1) return dp[left][right][turn];

        int points = 0;

        if(turn) {
            points = max(piles[left] + solve(piles,left+1,right,0),
                        piles[right] + solve(piles,left,right-1,0));
        } else {
            points = min(-piles[left] + solve(piles,left+1,right,1),
                        -piles[right] + solve(piles,left,right-1,1)); 
        }
        return dp[left][right][turn] = points;

    }
    bool stoneGame(vector<int>& piles) {
        // sum of piles -> odd -> tie not possible
        // no of piles -> even
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return (solve(piles,0,n-1,1) > 0);
    }
};