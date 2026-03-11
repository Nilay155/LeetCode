class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<int,vector<int>,greater<int>> indexes;

        for(int i = 0 ; i < n ; i++) {

            if(pq.size() >= k) {
                auto [top,index] = pq.top(); pq.pop();

                if(top > nums[i]) pq.push({top,index});
                else pq.push({nums[i],i});
            } else {
                pq.push({nums[i],i});
            }
        }
        
        
        while(!pq.empty()) {
            indexes.push(pq.top().second);
            pq.pop();
        }

        vector<int> ans;
        while(!indexes.empty()) {
            ans.push_back(nums[indexes.top()]);
            indexes.pop();
        }
        return ans;
    }
};