class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        int n = grid.size(), m = grid[0].size();

        vector<int> result(k,-1);

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[0][0] = true;
        pq.push({grid[0][0],0,0});
        int count = 0;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        unordered_map<int,vector<int>> mpp;
        for(int i = 0 ; i < k ; i++) mpp[queries[i]].push_back(i);

        sort(queries.begin(),queries.end());
        int t = 0;

        while(!pq.empty()) {
            int sz = pq.size();

            for(int j = 0 ; j < sz ; j++) {
                auto p = pq.top(); pq.pop();
                auto [val,x,y] = p;

                for(int i = 0 ; i < 4 ; i++) {
                    int newX = x + dx[i], newY = y + dy[i];

                    if(newX >= 0 && newY >= 0 && newX < n && newY < m && !visited[newX][newY]) {
                        pq.push({grid[newX][newY],newX,newY});
                        visited[newX][newY] = true;
                    }
                }
                while(t < k && val >= queries[t]) {
                    if(!mpp[queries[t]].empty()) {
                        result[mpp[queries[t]].back()] = count;
                        mpp[queries[t]].pop_back();
                    }
                    t++;
                }
                count += 1;
            }
        }

        for(int i = 0 ; i < k ; i++) {
            if(result[i] == -1) result[i] = count;
        }
        return result;
    }
};