class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        map<vector<int>,int> R,C;
        for(int i = 0 ; i < n ; i++) {
            R[grid[i]] += 1;
        }
        for(int i = 0 ; i < n ; i++) {
            vector<int> temp;
            for(int j = 0 ; j < n ; j++) {
                temp.push_back(grid[j][i]);
            }
            C[temp] += 1;
        }

        for(auto [arr,count] : R) {

            if(C.find(arr) != C.end()) {
                ans += (count * C[arr]);
            }
        }
        return ans;
    }
};