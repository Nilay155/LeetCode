class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int s = 0, e = m-1;

        while(s <= e) {
            int mid = (s + e) >> 1;

            // Peak Element in Mid Row
            int peak = INT_MIN , idx = -1;
            for(int i = 0 ; i < n ; i++) {
                if(peak < mat[mid][i]) {
                    peak = mat[mid][i], idx = i;
                }
            }

            int maxi1 = INT_MIN, maxi2 = INT_MIN;
            if(mid-1 >= 0) maxi1 = mat[mid-1][idx];
            if(mid+1 < m) maxi2 = mat[mid+1][idx];

            bool flag1 = false, flag2 = false;
            if(peak > maxi1 && peak > maxi2) {
                if(idx-1 >= 0) {
                    if(peak > mat[mid][idx-1]) flag1 = true;
                } else {
                    flag1 = true;
                }
                if(idx+1 < n) {
                    if(peak > mat[mid][idx+1]) flag2 = true;
                } else {
                    flag2 = true;
                }
            }

            if(flag1 && flag2) return {mid,idx};
            else {
                if(maxi1 > maxi2) {
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            }
        }
        return {-1,-1};

    }
};