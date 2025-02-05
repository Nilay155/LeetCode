class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        // books[i] -> thickness, height
        // books placing such that sum(width) <= shelfWidth

        // dp[i] -> minimum height to get to the i-th index
        vector<int> dp(n+1,1e9);
        dp[0] = 0;

        for(int i = 1 ; i <= n ; i++) {
            int width = 0;
            int height = 0;
            for(int j = i ; j >= 1 ; j--) {
                width += books[j-1][0];
                height = max(books[j-1][1],height);

                if(width <= shelfWidth) {
                    dp[i] = min(dp[i],height + dp[j-1]);
                }
            }
        }
        return dp[n];
    }   
};