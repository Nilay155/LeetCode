using ll = long long;
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> arr;

        for(int i = 0 ; i < n ; i++)
            arr.push_back({nums1[i],i});  
        sort(arr.rbegin(),arr.rend());

        vector<int> nums(n);
        for(int i = 0 ; i < n ; i++) {
            nums[i] = nums2[arr[i].second];
        }

        ll kSum = 0;
        vector<ll> ans(n);
        int j = n - 1;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(int i = n - 1 ; i >= 0 ; i--) {
            while(i < j && arr[i].first > arr[j].first) {
                if(minHeap.size() < k) {
                    kSum += nums[j];
                    minHeap.push(nums[j]);
                } else {
                    // count >= k
                    int top = minHeap.top();
                    if(nums[j] >= top) {
                        minHeap.pop();
                        kSum -= top;
                        minHeap.push(nums[j]);
                        kSum += nums[j];
                    }
                }
                j--;
            }
            ans[arr[i].second] = kSum;
        }
        return ans;
    }
};