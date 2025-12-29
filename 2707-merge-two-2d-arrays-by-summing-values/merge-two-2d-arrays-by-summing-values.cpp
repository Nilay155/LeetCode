class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        map<int,int> keyValue;
        for(auto arr : nums1) {
            keyValue[arr[0]] += arr[1];
        }
        for(auto arr : nums2) {
            keyValue[arr[0]] += arr[1];
        }

        vector<vector<int>> result;
        for(auto [id,val] : keyValue) {
            result.push_back({id,val});
        }
        return result;
    }
};