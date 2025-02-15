class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Brute Force -> O(n^2)
        int n = nums1.size();
        int m = nums2.size();
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                int sum = nums1[i] + nums2[j];
                if(maxHeap.size() >= k) {
                    if(maxHeap.top().first <= sum) break;
                    else maxHeap.pop();
                }
                maxHeap.push({sum,{nums1[i],nums2[j]}});
            }
        }

        vector<vector<int>> ans;
        while(k--) {
            auto p = maxHeap.top().second; maxHeap.pop();
            ans.push_back({p.first,p.second});
        }
        return ans;
    }
};