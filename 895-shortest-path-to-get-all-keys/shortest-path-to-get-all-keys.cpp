class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].length();

        int start_i = -1, start_j = -1, temp1 = 0, temp2 = 0;
        map<pair<int,int>,int> mpp;
        unordered_map<int,pair<int,int>> map;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == '@') {
                    start_i = i,start_j = j;
                } else if(grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    mpp[{i,j}] = temp1++;
                    map[grid[i][j]-'a'] = {i,j};
                } 
            }
        }  
        if(start_i == -1) return -1;
        
        int target = (1 << temp1) - 1;

        queue<tuple<int,int,int>> q;
        q.push({start_i,start_j,0});
        int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};
        int dist[30][30][65];
        memset(dist,-1,sizeof(dist));
        dist[start_i][start_j][0] = 0;
        
        while(!q.empty()) {
            auto [x,y,keyMask] = q.front(); q.pop();
            // cout << x << " : " << y << " : " << keyMask << endl;
            int moves = dist[x][y][keyMask];
            if(keyMask == target) return moves;

            for(int k = 0 ; k < 4 ; k++) {
                int newX = dx[k] + x;
                int newY = dy[k] + y;

                if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;

                if(grid[newX][newY] =='#') continue;
                
                int newKeyMask = keyMask;
                if(grid[newX][newY] >= 'A' && grid[newX][newY] <= 'F') {
                    int temp = mpp[map[grid[newX][newY] - 'A']];
                    if(newKeyMask & (1 << temp)) {
                        // good
                    } else {
                        continue;
                    }
                } 

                if(grid[newX][newY] >= 'a' && grid[newX][newY] <= 'f') {
                    newKeyMask |= (1 << mpp[{newX,newY}]);
                } 

                if(dist[newX][newY][newKeyMask] == -1 || 
                   dist[newX][newY][newKeyMask] > moves+1) {
                    dist[newX][newY][newKeyMask] = moves+1;
                    q.push({newX,newY,newKeyMask});
                   }
            }
        }
        return -1;
    }
};