class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> ans;
        for(int j = 0 ; j < m ; j++) {
            int s1 = B[j][0], e1 = B[j][1];
            for(int i = 0 ; i < n ; i++) {
                int s2 = A[i][0], e2 = A[i][1];

                if(s1 < s2) {
                    if(s2 <= e1) ans.push_back({max(s1,s2),min(e1,e2)});
                } else {
                    if(s1 <= e2) ans.push_back({max(s1,s2),min(e1,e2)});
                }
            }
        }
        return ans;
    }
};