class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> counts;
        for(int num : nums) counts[num] += 1;

        vector<vector<int>> arr;
        for(auto [num,count] : counts) arr.push_back({num,count});
        sort(arr.rbegin(),arr.rend());

        int prefix = arr[0][1], ans = 0;
        for(int i = 1 ; i < (int)arr.size() ; i++) {
            ans += prefix;
            prefix += arr[i][1];
        }
        return ans;
    }
};