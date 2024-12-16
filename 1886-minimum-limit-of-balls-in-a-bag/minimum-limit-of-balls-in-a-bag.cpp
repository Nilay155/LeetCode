class Solution {
public:
    bool isPossible(vector<int> &nums,int maxOperations,int k) {
        int n = nums.size();
        int operations = 0;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] > k) {
                operations += (nums[i]%k == 0) ? (nums[i]/k)-1 : (nums[i]/k);
            }
        }
        return operations <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int start = 1;
        int end = nums[n-1];

        while(start <= end) {
            int mid = (start + end) >> 1;
            if(isPossible(nums,maxOperations,mid)) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return start;
    }
};