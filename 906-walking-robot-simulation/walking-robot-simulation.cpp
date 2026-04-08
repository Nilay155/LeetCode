class Solution {
private:
    int ans = 0;
    map<pair<int,int>,bool> obstacles;
    pair<int,int> move(int x,int y,int d,int k) {

        for(int m = 1 ; m <= k ; m++) {
            int u = x, v = y;
            
            if(d == 0) v += 1;
            else if(d == 1) u += 1;
            else if(d == 2) v -= 1;
            else u -= 1;
            
            if(obstacles.count({u,v})) break;

            x = u, y = v;
        }
        ans = max(ans,x * x + y * y);
        return {x,y};
    }
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        int n = c.size(), m = o.size();

        bool firstMove = false;
        int x = 0, y = 0, d = 0, mod = 4;
        obstacles.clear();

        for(int i = 0 ; i < m ; i++) {
            int x = o[i][0], y = o[i][1];
            obstacles[{x,y}] = true;
        }
        for(int i = 0 ; i < n ; i++) {
            int k = c[i];
            if(k == -1) d = (d + 1) % mod;
            else if(k == -2) d = ((d - 1) % mod + mod) % mod;
            else {
                auto [u,v] = move(x,y,d,k);
                x = u, y = v;
            }
            // cout << x << " : " << y << "\n";
        }
        return ans;
    }
};