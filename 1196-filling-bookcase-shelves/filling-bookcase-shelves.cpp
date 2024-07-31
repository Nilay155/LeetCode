class Solution {
public:
    int func(vector<vector<int>> &books,int shelfWidth,int i,int n,vector<int> &dp) {

        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int minHeight = 1e9;
        int width = 0;
        int maxHeightShelf = 0;
        
        for(int j = i ; j < n ; j++) {
            
            int height = books[j][1];
            int thickness = books[j][0];
            
            width += thickness;
            maxHeightShelf = max(maxHeightShelf,height);

            if(width <= shelfWidth) {
                int recursion = maxHeightShelf + func(books,shelfWidth,j+1,n,dp);
                minHeight = min(minHeight,recursion);
            } 
        }
        return dp[i] = minHeight;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int m = books[0].size();

        int i = 0;
        vector<int> dp(n,-1);

        return func(books,shelfWidth,i,n,dp);
    }
};