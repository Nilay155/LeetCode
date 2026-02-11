class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            unordered_map<int,bool> E,O;
            for(int j = i ; j < n ; j++) {
                if(nums[j] & 1) O[nums[j]] = true;
                else E[nums[j]] = true;
                
                if(O.size() == E.size()) {
                    ans = max(ans,j - i + 1);
                }
            }
        }
        return ans;
    }
};