class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();

        if(n > m) return findMedianSortedArrays(B,A);
        int total = n + m;
        int half = total / 2;
        int l = 0, r = n-1;

        while(true) {

            int mid1 = (l + r) >> 1;
            int mid2 = half - mid1 - 2;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 >= 0 && mid1 < n) l1 = A[mid1];
            if(mid2 >= 0 && mid2 < m) l2 = B[mid2];
            if(mid1+1 >= 0 && mid1+1 < n) r1 = A[mid1+1];
            if(mid2+1 >= 0 && mid2+1 < m) r2 = B[mid2+1];

            if(l1 <= r2 && l2 <= r1) {
                // Correct Partition
                if(total%2) return double(min(r1,r2)) / 1.00;
                else return double(min(r1,r2) + max(l1,l2)) / 2.00;
            }
            else if(l2 > r1) {
                l = mid1 + 1;
            } 
            else {
                r = mid1 - 1;
            }
        }
        return -1.0;
    }
};