class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0 ; i < m ; i++) {
            int c = 0;
            for(int j = 0 ; j < n ; j++) {
                
                if(matrix[j][i] == 1) c += 1;
                else c = 0;

                matrix[j][i] = c;
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            priority_queue<int> pq;
            for(int j = 0 ; j < m ; j++) {
                pq.push(matrix[i][j]);
            }
            int l = INT_MAX, b = 0;
            while(!pq.empty()) {
                int top = pq.top(); pq.pop();
                l = min(l,top);
                b += 1;
                ans = max(ans,l*b);
            }
        }
        return ans;
    }
};