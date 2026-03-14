class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size(), c = 0;
        for(int f : nums) if(f == 0) c += 1;

        if(c > k) return 0;
        else k -= c;

        // Now we have all non-zero elements to make up a sum
        for(int i = 0 ; i < n ; i++) if(nums[i] == 0) nums[i] = 1;

        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0 ; i < n ; i++) pq.push(nums[i]);

        while(k--) {
            int top = pq.top(); pq.pop();
            top = top + 1;
            pq.push(top);
        }
        long long ans = 1;
        int MOD = 1e9 + 7;
        while(!pq.empty()) {
            int top = pq.top(); pq.pop();
            ans = ans * (long long) top;
            ans = ans % MOD;
        }
        return ans;
    }
};