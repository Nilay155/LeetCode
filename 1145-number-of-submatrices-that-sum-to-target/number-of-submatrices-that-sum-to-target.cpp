class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // Brute Force -> O(n*m*n*m) + prefix Sums and count
        // optimal Soln -> O()
        int n = matrix.size(), m = matrix[0].size(), count = 0;
        for(int r = 0 ; r < n ; r++) {
            vector<int> cols(m,0);
            for(int i = r ; i >= 0 ; i--) {
                for(int j = 0 ; j < m ; j++) {
                    cols[j] += matrix[i][j];
                }
                    unordered_map<int,int> mpp;
                    int sum = 0;
                    mpp[sum] = 1;
                    for(int j = 0 ; j < m ; j++) {
                        sum += cols[j];
                        int r = sum-target;
                        if(mpp.find(r) != mpp.end()) {
                            count += mpp[r];
                        }
                        mpp[sum] += 1;
                    }
            }
        }
        return count;
    }
};