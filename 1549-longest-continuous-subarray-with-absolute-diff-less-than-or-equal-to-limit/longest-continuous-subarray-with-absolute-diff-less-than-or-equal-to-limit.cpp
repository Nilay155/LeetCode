class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> mst;
        int ans = 0;

        int l = 0, r = 0;
        while(r < n) {
            mst.insert(nums[r]);

            while(l < r && !mst.empty() && *(mst.rbegin())-*(mst.begin()) > limit) {
                auto it = mst.find(nums[l]);
                if (it != mst.end())
                    mst.erase(it);
                l += 1;
            }
            
            if(r-l+1 > ans) {
                // cout << l << "  " << r << "\n";
                ans = r-l+1;
            }
            r += 1;
        }
        return ans;
    }
};