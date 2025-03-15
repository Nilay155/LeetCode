class Solution {
private:
    bool check(vector<int> &nums,int k,int mid) {
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i < n ; ++i) {
            if(nums[i] <= mid) {
                count += 1;
                i += 1;
            }
        }
        return count >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        // Brute Force -> O(nk) -> TLE
        // K -> minimise -> Binary Search
        int low = 0;
        int high = *max_element(nums.begin(),nums.end());

        while(low <= high) {
            int mid = (low + high) >> 1;
            if(check(nums,k,mid)) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};