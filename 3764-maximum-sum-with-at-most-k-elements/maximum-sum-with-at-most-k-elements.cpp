using ll = long long;
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size(), m = grid[0].size();
        ll ans = 0;
        if(k == 0)
            return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0 ; i < n ; i++) {
            int limit = limits[i];
            if(limit == 0)
                continue;
            priority_queue<int,vector<int>,greater<int>> q;

            for(int j = 0 ; j < m ; j++) {

                if((int) q.size() >= limit) {
                    int top = q.top();

                    if(top < grid[i][j]) {
                        q.pop();
                        q.push(grid[i][j]);
                    } 
                } else {
                    q.push(grid[i][j]);
                }
            }

            while(!q.empty()) {

                if((int) pq.size() >= k) {
                    int top = pq.top();
                    if(top < q.top()) {
                        pq.pop();
                        pq.push(q.top());                        
                    }
                } else {
                    pq.push(q.top());
                }
                q.pop();
            }
        }
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};