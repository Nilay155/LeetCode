class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            pq.push(nums[i]);
        }
        while(pq.size() > k) pq.pop();
    }
    
    int add(int val) {
        if(pq.size() < K) {
            pq.push(val);
            return pq.top();
        }

        int top = pq.top(); pq.pop();

        if(val > top) pq.push(val);
        else pq.push(top);
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */