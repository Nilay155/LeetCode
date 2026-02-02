class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        long long p1 = 0, p2 = 0,ans = 0;

        while(i < n && j < m) {

            if(nums1[i] > nums2[j]) {
                p2 += nums2[j];
                j += 1;
            } else if(nums1[i] < nums2[j]) {
                p1 += nums1[i];
                i += 1;
            } else {
                ans += max(p1,p2) + nums1[i];
                p1 = p2 = 0;
                i += 1,j += 1;
            }
        }

        while(i < n) {
            p1 += nums1[i];
            i += 1;
        }
        while(j < m) {
            p2 += nums2[j];
            j += 1;
        }
        ans += max(p1,p2);
        return ans % MOD;
    }
};