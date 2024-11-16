class Solution {
public:
    // int dp[101][101][101];
    int solve(vector<int> &boxes,int left,int right,int count,vector<vector<vector<int>>> &dp) {
        if(left > right) return 0;
        if(dp[left][right][count] != -1) return dp[left][right][count];
        int l = left, cnt = count;
        while(left+1 <= right && boxes[left] == boxes[left+1]) {
            count += 1;
            left += 1;
        }
        int ans = (count+1)*(count+1) + solve(boxes,left+1,right,0,dp);
        
        for(int k = left+1 ; k <= right ; k++) {
            if(boxes[left] == boxes[k]) {
                ans = max(ans,solve(boxes,k,right,count+1,dp) + solve(boxes,left+1,k-1,0,dp));
            }
        }
        return dp[l][right][cnt] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(boxes,0,n-1,0,dp);
    }
};