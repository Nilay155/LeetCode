class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // length = 2.1e5 (approx) 
        int k = nums.size();
        // Out of all elements in nums, I need to find k-elements such that
        // every element is part of every nums[k] array and has the minimum range

        vector<pair<int,int>> arr;
        for(int i = 0 ; i < k ; i++) {
            for(int j = 0 ; j < (int) nums[i].size() ; j++) {
                arr.push_back({nums[i][j],i});
            }
        }
        sort(arr.begin(),arr.end());

        int l = 0, r = 0;
        int ansL = -1e9, ansR = 1e9;
        unordered_set<int> st;
        unordered_map<int,int> freq;
        while(r < (int)arr.size()) {
            st.insert(arr[r].second);
            freq[arr[r].second] += 1;

            while(l <= r && st.size() >= k) {
                // Now I have exact one element from all k indexes
                if(ansL == -1e9 && ansR == 1e9) {
                    // first valid range
                    ansL = arr[l].first, ansR = arr[r].first;
                } else {
                    if(ansR - ansL > arr[r].first - arr[l].first) {
                        ansR = arr[r].first;
                        ansL = arr[l].first;
                    }
                }
                freq[arr[l].second] -= 1;
                if(freq[arr[l].second] == 0) {
                    freq.erase(arr[l].second);
                    st.erase(arr[l].second);
                }
                l += 1;
            }
            r += 1;
        }
        return {ansL,ansR};
    }
};