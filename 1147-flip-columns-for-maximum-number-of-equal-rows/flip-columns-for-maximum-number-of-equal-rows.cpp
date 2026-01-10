class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        map<vector<int>,int> map;

        for(int i = 0 ; i < n ; i++) {
            int count = 0, ele = -1;
            vector<int> arr;
            for(int j = 0 ; j < m ; j++) {
                if(ele == -1) {
                    ele = matrix[i][j];
                    count += 1;
                } else if(ele == matrix[i][j]) {
                    count += 1;
                } else {
                    arr.push_back(count);
                    ele = matrix[i][j];
                    count = 1;
                }
            }
            arr.push_back(count);
            map[arr] += 1;
        }

        int ans = 0;
        for(auto [arr,count] : map) {
            ans = max(ans,count);
        }
        return ans;
    }
};