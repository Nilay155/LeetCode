#define p pair<int,pair<int,int>>
class Solution {
private:
    bool isValid(int x,int y,int n,int m) {
        if(x >= 0 && x < n && y >= 0 && y < m) return true;
        else return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        pq.push({0,{0,0}});

        int ans = INT_MAX;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};

        while(!pq.empty()) {
            auto temp = pq.top(); pq.pop();
            int maxDiff = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            if(x == n-1 && y== m-1) ans = min(ans,maxDiff);

            if(vis[x][y]) continue;
            vis[x][y] = true;

            for(int i = 0 ; i < 4 ; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(!isValid(newX,newY,n,m)) continue;
                if(vis[newX][newY]) continue;

                int diff = abs(heights[x][y] - heights[newX][newY]);
                pq.push({max(diff,maxDiff),{newX,newY}});
            }   
        }
        return ans;
    }
};