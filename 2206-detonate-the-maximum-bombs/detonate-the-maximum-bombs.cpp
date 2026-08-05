class Solution {
private:
    double distance(int x1,int y1,int x2,int y2) {
        return (double) sqrt(1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2));
    }
    bool check(double d,double r) {

        if(r >= d)
            return true;
        return false;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size(),ans = 0;
        for(int i = 0 ; i < n ; i++) {

            // detonate bomb i
            int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            int count = 0;
            vector<bool> vis(n,false);
            vis[i] = true;

            queue<tuple<int,int,int>> q;
            q.push({x1,y1,r1});

            while(!q.empty()) {
                auto [x1,y1,r1] = q.front(); q.pop();
                count += 1;

                for(int j = 0 ; j < n ; j++) {
                    int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                    if(!vis[j]) {
                        double dist = distance(x1,y1,x2,y2);
                        bool flag = check(dist,(double) r1);

                        if(flag) {
                            vis[j] = true;
                            q.push({x2,y2,r2});
                        }
                    }
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};