class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        // Brute-Force -> O(n*m)
        // Optimal-Soln -> O(mlogk) + O(k)
        vector<bool> ans(m);
        vector<pair<int,int>> v;
        for(int i = 0 ; i < n-1 ; i++) {
            if(
                (nums[i]&1) == (nums[i+1]&1)
            ) {
                v.push_back({i,i+1});
            }
        }
        int k = v.size();

        sort(v.begin(),v.end());
        for(int i = 0 ; i < m ; i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            int low = 0;
            int high = k-1;
            int lowerBound = -1;
            // lower bound
            while(low <= high) {
                int mid = (low + high) >> 1;
                if(v[mid].first >= left) {
                    lowerBound = mid;
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
            if(lowerBound == -1) {
                ans[i] = true;
            } else {
                int first = v[lowerBound].first;
                int second = v[lowerBound].second;

                if((first >= left && first < right) && (second > left && second <= right)) {
                    ans[i] = false;
                } else {
                    ans[i] = true;
                }
            }
        }
        return ans;
    }
};