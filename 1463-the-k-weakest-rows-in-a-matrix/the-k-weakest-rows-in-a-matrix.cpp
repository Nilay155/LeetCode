class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> counts;
        for(int i = 0 ; i < n ; i++) {
            int s = 0, e = m - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;
                if(mat[i][mid] == 0) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            counts.push_back({e + 1, i});
        }
        sort(counts.begin(),counts.end(),[&](vector<int> &A,vector<int> &B) {

            if(A[0] == B[0]) return A[1] < B[1];
            else return A[0] < B[0];
        });

        vector<int> ans;
        for(int i = 0 ; i < k ; i++) ans.push_back(counts[i][1]);
        return ans;
    }
};