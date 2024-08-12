class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int res = -1;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            minHeap.push(nums[i]);
        }
        res = k;
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size() > res) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */