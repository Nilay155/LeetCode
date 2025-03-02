class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        map<int,int> mpp;
        for(auto &it : nums1) {
            mpp[it[0]] += it[1];
        }
        for(auto &it : nums2) {
            mpp[it[0]] += it[1];
        }
        vector<vector<int>>res;
        for(auto& it : mpp) {
            res.push_back({it.first,it.second});
        }
        return res;
    }
};