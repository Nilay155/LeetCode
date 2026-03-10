class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int f : nums) freq[f] += 1;

        priority_queue<pair<int,int>> pq;
        for(auto [e,c] : freq) pq.push({c,e});
        
        vector<int> ans(k);
        for(int i = 0 ; i < k ; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
        
    }
};