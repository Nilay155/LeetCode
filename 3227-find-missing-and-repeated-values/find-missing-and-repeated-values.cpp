class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int start = 1;
        int end = n*n;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ;i++) {
            for(int j = 0 ; j < n ; j++) {
                mpp[grid[i][j]]++;
            }
        }

        vector<int> ans;
        for(int i = start ; i <= end ; i++) {
            if(mpp[i] > 1) {
                ans.push_back(i);
            }
        }
        for(int i = start ; i <= end ; i++) {
            if(mpp[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};