class Solution {
public:
    bool check(int x,int y,int n,int m) {
        if(x >= 0 && x < n && y >= 0 && y < m) return true;
        else return false;
    }
    int bfs(vector<vector<int>> &forest,int sx,int sy,int ex,int ey) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(forest.size(),vector<int>(forest[0].size(),0));

        vis[sx][sy] = 1;
        q.push({sx,sy});

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};

        int steps = 0;
        bool flag = false;

        while(!q.empty()) {
            int sz = q.size();
            
            for(int i = 0 ; i < sz ; i++) {
                auto p = q.front(); q.pop();
                int x = p.first, y = p.second;

                if(x == ex && y == ey) return steps;

                for(int j = 0 ; j < 4 ; j++) {
                    int newX = dx[j] + x;
                    int newY = dy[j] + y;

                    if(check(newX,newY,forest.size(),forest[0].size()) && !vis[newX][newY] && forest[newX][newY] != 0) {
                        q.push({newX,newY});
                        vis[newX][newY] = 1;
                    }
                }

            }
            steps += 1;
        }
        return INT_MAX;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();

        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,pair<int,int>> mpp;

        pq.push(1);
        mpp[1] = {0,0};

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(forest[i][j] > 1) {
                    pq.push(forest[i][j]);
                    mpp[forest[i][j]] = {i,j};
                }
                
            }
        }

        int res = 0;
        while(!pq.empty()) {
            int start = pq.top(); pq.pop();
            if(pq.empty()) break;
            int end = pq.top();
            
            auto p1 = mpp[start], p2 = mpp[end];
            int temp = bfs(forest,p1.first,p1.second,p2.first,p2.second);

            if(temp == INT_MAX) return -1;
            else res += temp;
        }
        return res;

    }
};