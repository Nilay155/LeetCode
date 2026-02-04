class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
    int u = -1, v = -1;
    
    for(int i = n-2 ; i >= 0 ; i--) {
        if(nums[i] < nums[i+1]) {
            u = i, v = i+1;
            break;
        }
    }
    if(u == -1) {
        reverse(nums.begin(),nums.end());
        return;
    }
    int index = -1;
    for(int k = v ; k < n ; k++) {
        if(nums[k] > nums[u]) {
            index = k;
        }
    }
    swap(nums[index],nums[u]);
    sort(nums.begin() + v,nums.end());
    }
};