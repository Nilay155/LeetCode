class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9 + 7;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0 ; i < n ; i++) pq.push({nums[i],i});

        int sum = 0, count = 0;
        while(!pq.empty() && count < right) {
            auto [subArraySum,k] = pq.top(); pq.pop();
            count += 1;

            if(count >= left && count <= right) {
                sum = (sum + subArraySum) % MOD;
            } 

            if(k + 1 < n) {
                pq.push({subArraySum + nums[k + 1],k + 1});
            }      
        }
        return sum;
    }
};