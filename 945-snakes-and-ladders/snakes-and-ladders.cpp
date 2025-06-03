class Solution {
private:
    int bfs(vector<vector<int>> &board,unordered_map<int,pair<int,int>> &mpp) {
        queue<pair<int,int>> q;
        vector<bool> vis(mpp.size()+1,false);
        int n = board.size();
        q.push({1,0});
        vis[1] = true;

        while(!q.empty()) {
            auto [top,hops] = q.front(); q.pop();

            if(top == n*n) return hops;

            for(int k = top+1 ; k <= min(top+6,n*n) ; k++) {
                auto [x,y] = mpp[k];
                if(vis[k]) continue;

                if(board[x][y] != -1) {
                    vis[k] = true;
                    q.push({board[x][y],hops+1});
                } else {
                    vis[k] = true;
                    q.push({k,hops+1});
                }
            }
        }
        return -1;
    }
private:
    int dijkstra(vector<vector<int>> &board,unordered_map<int,pair<int,int>> &mpp) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(mpp.size()+1,INT_MAX);
        int n = board.size();
        return -1;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int,pair<int,int>> mpp;
        int n = board.size();

        int count = 1;
        bool flag = true;
        for(int i = n-1; i >= 0 ; i--) {
            for(int j = 0 ; j < n ; j++) {
                if(flag) mpp[count++] = {i,j};
                else mpp[count++] = {i,n-j-1};
            }
            flag = !flag;
        }
        return bfs(board,mpp);
        // dijkstra(board,mpp);
    }
};