class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        // int i = 0, j = 0, n = nums1.size();
        return nums2[0] - nums1[0];
    }
};