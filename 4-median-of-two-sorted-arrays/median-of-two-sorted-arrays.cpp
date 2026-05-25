class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) 
            return findMedianSortedArrays(nums2,nums1);
        
        int half = (m + n + 1) / 2;

        int s = 0, e = min(m,half);
        while(s <= e) {
            int mid = s + (e - s) / 2;
            int k1 = mid;
            int k2 = half - k1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(k1 - 1 >= 0) l1 = nums1[k1 - 1];
            if(k1 < m) r1 = nums1[k1];
            if(k2 - 1 >= 0) l2 = nums2[k2 - 1];
            if(k2 < n) r2 = nums2[k2];

            if(l1 <= r2 && l2 <= r1) {
                // optimal condition
                if((m + n) & 1) {
                    // odd length
                    return (double) (max(l1,l2)) / 1.00;
                } else {
                    // even length
                    return (double) (min(r1,r2) + max(l1,l2)) / 2.00;
                }
            } else if(l1 > r2) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }

        }
        return 0.00;
    }
};