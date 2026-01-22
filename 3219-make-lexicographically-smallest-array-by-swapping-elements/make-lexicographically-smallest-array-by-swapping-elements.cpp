class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        if(n == 1) return nums;

        unordered_map<int,vector<int>> groups;

        vector<vector<int>> sorted;
        for(int i = 0 ; i < n ; i++) sorted.push_back({nums[i],i});

        sort(sorted.begin(),sorted.end());
        vector<int> group(n,-1);
        int gno = 0;
    
        for(int i = 1 ; i < n ; i++) {
            if(sorted[i][0] - sorted[i-1][0] <= limit) {
                if(groups.find(gno) == groups.end()) {
                    groups[gno].push_back(sorted[i-1][0]);
                    group[sorted[i-1][1]] = gno;
                    groups[gno].push_back(sorted[i][0]);
                    group[sorted[i][1]] = gno;
                } else {
                    groups[gno].push_back(sorted[i][0]);
                    group[sorted[i][1]] = gno;
                }
            } else {
                gno += 1;
            }
        }
        vector<int> ans(n);
        for(int i = n-1 ; i >= 0 ; i--) {
            if(group[i] != -1) {
                ans[i] = groups[group[i]].back();
                groups[group[i]].pop_back();
            } else {
                ans[i] = nums[i];
            }
        }
        return ans;
    }
};