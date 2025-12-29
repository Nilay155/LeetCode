class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        int i = 0, n = nums1.size();
        int j = 0, m = nums2.size();

        while(i < n && j < m) {
            if(nums1[i][0] == nums2[j][0]) {
                nums1[i][1] += nums2[j][1];
                nums2[j][0] = -1;
                i++;
                j++;
            } else if(nums1[i][0] > nums2[j][0]) {
                j++;
            } else {
                i++;
            }
        }
        i = 0, j = 0;
        vector<vector<int>> result;
        while(i < n && j < m) {
            if(nums1[i][0] < nums2[j][0]) {
                result.push_back({nums1[i][0],nums1[i][1]});
                i++;
            } else {
                if(nums2[j][0] != -1)
                    result.push_back({nums2[j][0],nums2[j][1]});
                j++;
            }
        }
        while(i < n) {
            result.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }
        while(j < m) {
            if(nums2[j][0] != -1)
                result.push_back({nums2[j][0],nums2[j][1]});
            j++;
        }
        return result;
    }
};