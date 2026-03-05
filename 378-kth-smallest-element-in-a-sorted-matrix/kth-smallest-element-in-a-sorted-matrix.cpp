class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        // O(n*logn) [time] + O(n) [space]
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        for(int i = 0 ; i < n ; i++) {
            pq.push({matrix[i][0],i,0});
        }

        while(k > 1) {
            auto [val,i,j] = pq.top(); pq.pop();

            if(j + 1 < n)
                pq.push({matrix[i][j+1],i,j+1});
            k -= 1;
        }
        auto [val,i,j] = pq.top(); pq.pop();
        return val;
    }
};