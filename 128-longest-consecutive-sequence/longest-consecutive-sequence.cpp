class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int,int> map;

        for(int num : nums) map[num] = 1;

        int ans = 0;
        for(auto& it : map) {
            int prev = it.first - 1;
            if(map.find(prev) != map.end()) {
                map[it.first] += map[prev];
            }
            ans = max(ans,map[it.first]);
        }
        return ans;
    }
};