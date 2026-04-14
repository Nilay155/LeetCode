class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int maxJump = n*n, k = 1;
        vector<pair<int,int>> indexes(n*n + 1);
        bool flag = true;
        for(int i = n - 1  ; i >= 0 ; i--) {
            if(flag) for(int j = 0 ; j < n ; j++) indexes[k++] = {i,j};
            else for(int j = n - 1 ; j >= 0 ; j--) indexes[k++] = {i,j};
            flag = !flag;
        }

        queue<pair<int,int>> q;
        vector<bool> vis(n * n + 1,false);
        q.push({1,0});
        vis[1] = true;

        while(!q.empty()) {
            auto [currPosition,moves] = q.front(); q.pop();
            if(currPosition == n*n) 
                return moves;
            
            for(int jump = 1 ; jump <= 6 && currPosition + jump <= n*n ; jump += 1) {
                int nextMove = jump + currPosition;

                auto [x,y] = indexes[nextMove];
                if(board[x][y] != -1) {
                    int newPosition = board[x][y];
                    if(vis[newPosition]) continue;
                    vis[newPosition] = true;
                    q.push({newPosition,moves + 1});
                } else {
                    if(vis[nextMove]) continue;
                    vis[nextMove] = true;
                    q.push({nextMove,moves + 1});
                }
            }
        }
        return -1;
    }
};