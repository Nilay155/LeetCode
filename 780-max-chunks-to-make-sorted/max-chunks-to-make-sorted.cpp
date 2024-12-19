class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> nums(n);
        nums[0]=arr[0];
        for(int i = 1 ; i < n ; i++) {
            nums[i] = max(nums[i-1],arr[i]);
        }
        int res = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == i) res += 1;
        }
        return res;
    }
};