class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();

        vector<int> prefix(n,0);
        for(int i = 1 ; i < n ; i++) {
            if(
                (nums[i]%2 == 0 && nums[i-1]%2 == 0)  ||
                (nums[i]%2 == 1 && nums[i-1]%2 == 1)
            ) {
                prefix[i] = prefix[i-1];
            } else {
                prefix[i] = 1 + prefix[i-1];
            }
        } 
        vector<bool> ans;
        for(int i = 0 ; i < m ; i++) {
            int l = queries[i][0], r = queries[i][1];
            int pairs = r-l;
            int currPairs = prefix[r] - prefix[l];
            if(l == r) ans.push_back(true);
            else if(currPairs == pairs) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};