class Solution {
public:

    bool check(int x,int y,int n,int m,int prevColor,vector<vector<int>> &image) {
        if(x >= 0 && x < n && y >= 0 && y < m && image[x][y] == prevColor) return true;
        else return false;
    }
    void dfs(vector<vector<int>> &image,int x,int y,int &color,int prevColor,int &n,int &m) {

        image[x][y] = color;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        for(int i = 0 ; i < 4 ; i++) {
            int newX = dx[i] + x;
            int newY = dy[i] + y;

            if(check(newX,newY,n,m,prevColor,image)) {
                dfs(image,newX,newY,color,prevColor,n,m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int prevColor = image[sr][sc];
        if(prevColor != color)
            dfs(image,sr,sc,color,prevColor,n,m);
        return image;
    }
};